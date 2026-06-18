///José Vinício Olivindo Dias

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* ant;
    struct No* prox;
} No;

void inserir(No** inicio, int valor) {

    No* novo = malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
        return;
    }

    No* atual = *inicio;

    while (atual->prox)
        atual = atual->prox;

    atual->prox = novo;
    novo->ant = atual;
}

No* buscaSequencial(No* inicio, int chave) {

    while (inicio != NULL) {

        if (inicio->valor == chave)
            return inicio;

        inicio = inicio->prox;
    }

    return NULL;
}

No* encontrarMeio(No* inicio, No* fim) {

    No* lento = inicio;
    No* rapido = inicio;

    while (
        rapido != fim &&
        rapido->prox != fim
    ) {

        rapido = rapido->prox;

        if (rapido != fim) {
            rapido = rapido->prox;
            lento = lento->prox;
        }
    }

    return lento;
}

No* buscaBinaria(No* inicio, int chave) {

    No* esquerda = inicio;
    No* direita = NULL;

    while (esquerda != direita) {

        No* meio = encontrarMeio(esquerda, direita);

        if (meio == NULL)
            return NULL;

        if (meio->valor == chave)
            return meio;

        if (chave > meio->valor)
            esquerda = meio->prox;
        else
            direita = meio;
    }

    return NULL;
}

int main() {

    No* lista = NULL;

    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);
    inserir(&lista, 40);
    inserir(&lista, 50);

    int valor = 40;

    No* resultado;

    resultado = buscaSequencial(lista, valor);

    if (resultado)
        printf("Busca sequencial encontrou: %d\n", resultado->valor);
    else
        printf("Nao encontrado\n");

    resultado = buscaBinaria(lista, valor);

    if (resultado)
        printf("Busca binaria encontrou: %d\n", resultado->valor);
    else
        printf("Nao encontrado\n");

    return 0;
}