#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct No {
    char valor[MAX];
    struct No* esquerda;
    struct No* direita;
};

struct No* criarNo(char* valor) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    strcpy(novo->valor, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
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

int main() {
    struct No* raiz = criarNo("Hall de Entrada");
    raiz->esquerda = criarNo("Sala de Estar");
    raiz->direita = criarNo("Biblioteca");
    raiz->esquerda->esquerda = criarNo("Quarto");
 
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