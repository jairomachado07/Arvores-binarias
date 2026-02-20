#include <stdio.h>
#include <stdlib.h>

struct No {
    char valor[50];
    struct No* esquerda;
    struct No* direita;
};

int altura(struct No* raiz) {
    if (raiz == NULL) 
        return 0;
    int alt_esq = altura(raiz->esquerda);
    int alt_dir = altura(raiz->direita);
    return 1 + (alt_esq > alt_dir ? alt_esq : alt_dir);
}