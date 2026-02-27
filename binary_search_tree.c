#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    // Definição da estrutura do nó da árvore binária de busca
struct No {
    char valor[50];
    struct No* esquerda;
    struct No* direita;
};
    // Função para criar um novo nó
struct No* criarNo(const char* valor) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    strcpy(novo->valor, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}
    // Função para inserir um valor na árvore binária de busca
struct No* inserir(struct No* raiz, const char* valor) {
    if (raiz == NULL) 
        return criarNo(valor);
    
        if (strcmp(valor, raiz->valor) < 0)
            raiz->esquerda = inserir(raiz->esquerda, valor);
        else if (strcmp(valor, raiz->valor) > 0)
            raiz->direita = inserir(raiz->direita, valor);
    
        return raiz;
}
    // Função para buscar um valor na árvore binária de busca
struct No* encontrarMinimo(struct No* raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}
    // Função para mostrar os valores da árvore em ordem (esquerda, raiz, direita)
void emOrdem(struct No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%s ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

struct No* remover(struct No* raiz, const char* valor) {
    if (raiz == NULL) 
        return NULL;

    if (strcmp(valor, raiz->valor) < 0) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (strcmp(valor, raiz->valor) > 0) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        // Caso 1: sem filhos
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz->valor);
            free(raiz);
            return NULL;
        }

        // Caso 2: um único filho
        else if (raiz->esquerda == NULL) {
            struct No* temp = raiz->direita;
            free(raiz->valor);
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct No* temp = raiz->esquerda;
            free(raiz->valor);
            free(raiz);
            return temp;
        }

        // Caso 3: dois filhos
        else {
            struct No* sucessor = encontrarMinimo(raiz->direita);
            strcpy(raiz->valor, sucessor->valor);
            raiz->direita = remover(raiz->direita, sucessor->valor);
        }
    }

    return raiz;
}

void liberarArvore(struct No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int buscar(struct No* raiz, const char* valor) {
    if (raiz == NULL) 
        return 0;

    if (strcmp(valor, raiz->valor) == 0) 
        return 1;
    
    if (strcmp(valor, raiz->valor) < 0) 
        return buscar(raiz->esquerda, valor);
    
    return buscar(raiz->direita, valor);
}

int main() {
    struct No* raiz = NULL;
 
    raiz = inserir(raiz, "Pegadas de Lama");
    raiz = inserir(raiz, "Chave perdida");
    raiz = inserir(raiz, "Livro com página faltando");
    raiz = inserir(raiz, "Lençol manchado");
    raiz = inserir(raiz, "Gaveta perdida");
 
    printf("\nElementos em ordem: ");
    emOrdem(raiz);
 
    printf("\nBusca por ‘Lençol manchado’: %s", buscar(raiz, "Lençol manchado") ? "Encontrado" : "Não encontrado");
    printf("\nBusca por ‘Óculos’: %s\n", buscar(raiz, "Óculos") ? "Encontrado" : "Não encontrado");
 
    return 0;
}