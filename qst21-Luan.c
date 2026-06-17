#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

int main() {
    int N;

    printf("Digite a quantidade de nomes: ");
    scanf("%d", &N);

    char **nomes = (char **) malloc(N * sizeof(char *));
    if (nomes == NULL) {
        printf("Erro de alocacao!\n");
        return 1;
    }

    getchar();
    
    for (int i = 0; i < N; i++) {
        char buffer[TAM];

        printf("Digite o nome %d: ", i + 1);
        fgets(buffer, TAM, stdin);

        buffer[strcspn(buffer, "\n")] = '\0';

        nomes[i] = (char *) malloc(strlen(buffer) + 1);

        if (nomes[i] == NULL) {
            printf("Erro de alocacao!\n");
            return 1;
        }

        strcpy(nomes[i], buffer);
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (strlen(nomes[j]) > strlen(nomes[j + 1])) {
                char *temp = nomes[j];
                nomes[j] = nomes[j + 1];
                nomes[j + 1] = temp;
            }
        }
    }

    printf("\nNomes ordenados por tamanho:\n");
    for (int i = 0; i < N; i++) {
        printf("%s (tamanho: %lu)\n", nomes[i], strlen(nomes[i]));
    }

    for (int i = 0; i < N; i++) {
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}