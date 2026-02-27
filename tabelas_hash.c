#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10

// Estrutura de um nó da lista ligada
typedef struct Nodo {
    char nome[50];              // Armazena o nome
    struct Nodo* proximo;       // Ponteiro para o próximo nó
} Nodo;

// A tabela hash é um vetor de ponteiros para Nodo
Nodo* tabela_hash[TAMANHO_TABELA];

int funcao_hash(const char* chave) {
        int soma = 0;
        for (int i = 0; chave[i] != '\0'; i++) {
            soma += chave[i];
    }
    return soma % TAMANHO_TABELA;
}

void inserir(const char* nome) {
    int indice = funcao_hash(nome); // Descobre onde armazenar
    // Cria um nó
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(novo->nome, nome);

    // Insere no início da lista (head)
    novo->proximo = tabela_hash[indice];
    tabela_hash[indice] = novo;
}

Nodo* buscar(const char* nome) {
        int indice = funcao_hash(nome);
        Nodo* atual = tabela_hash[indice];
    
        while (atual != NULL) {
            if (strcmp(atual->nome, nome) == 0) {
                return atual; // Encontrou
        }
        atual = atual->proximo;
    }

    return NULL; // Não está na lista
}

void remover(const char* nome) {
        int indice = funcao_hash(nome);
        Nodo* atual = tabela_hash[indice];
        Nodo* anterior = NULL;
    
        while (atual != NULL) {
            if (strcmp(atual->nome, nome) == 0) {
                if (anterior == NULL) {
                    tabela_hash[indice] = atual->proximo; // Era o primeiro
            } else {
                    anterior->proximo = atual->proximo; // "Pula" o nó atual
            }
            free(atual);
            printf("'%s' removido.\n", nome);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("'%s' não encontrado.\n", nome);
}

int main() {
    inserir("Ana");
    inserir("Bruno");
    inserir("Carlos");
    inserir("Amanda"); // Pode colidir com "Ana"
 
    printf("Buscando 'Bruno': %s\n", buscar("Bruno") ? "Encontrado" : "Não encontrado");
    printf("Buscando 'João': %s\n", buscar("João") ? "Encontrado" : "Não encontrado");
 
    remover("Carlos");
    remover("João");
 
    return 0;
}