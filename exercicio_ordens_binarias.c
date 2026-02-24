#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct No {
    char valor[MAX];
    struct No* esquerda;
    struct No* direita;
}No;

 No* criarNo(const char* valor) {
    No* novo = (No*) malloc(sizeof(struct No));
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o nó.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(novo->valor, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void preOrdem(struct No* raiz);
void emOrdem(struct No* raiz);
void posOrdem(struct No* raiz);
void liberar(struct No* raiz);
No* inserir(No* raiz, const char* valor);

int main() {
    No* raiz = NULL; //iniciando a raiz como vazia
    raiz = inserir(raiz, "Hall de Entrada");
    raiz = inserir(raiz, "Sala de Estar");
    raiz = inserir(raiz, "Biblioteca");
    raiz = inserir(raiz, "Quarto");
 
    printf("Pré-ordem: ");
    preOrdem(raiz);
    printf("\n");
 
    printf("Em ordem: ");
    emOrdem(raiz);
    printf("\n");
 
    printf("Pós-ordem: ");
    posOrdem(raiz);
    printf("\n");
 
    liberar(raiz);
    return 0;
}

void preOrdem(struct No* raiz) {
    if (raiz != NULL) {
        printf("%s ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}
 
void emOrdem(struct No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%s ", raiz->valor);
        emOrdem(raiz->direita);
    }
}
 
void posOrdem(struct No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%s ", raiz->valor);
    }
}

void liberar(struct No* raiz) {
    if (raiz != NULL) {
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}

No* inserir(No* raiz, const char* valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (strcmp(valor, raiz->valor) < 0) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (strcmp(valor, raiz->valor) > 0) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}