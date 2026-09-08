#include <stdio.h>
#include <stdlib.h>

int soma_diagonal(int **mat, int n);
int **lerMatriz(int *n);
void imprimirMatriz(int **m, int n);

int main() {
    int n;
    printf("Insira o tamanho N da matriz: ");
    scanf("%d", &n);

    if(n <= 1) {
        printf("Tamanho invalido.\n");
        return 1;
    }

    int **matriz = lerMatriz(&n);
    
    imprimirMatriz(matriz, n);

    int soma = soma_diagonal(matriz, n);

    printf("Soma diagonal: %d\n", soma);

    free(matriz);

    return 0;
}

int soma_diagonal(int **mat, int n) {
    int soma = 0;

    for (int i = 0; i < n; i++) {
        soma += mat[i][i];
    }
    
    return soma;
}

int **lerMatriz(int *n) {
    int **M = (int **)malloc(sizeof(int) * (*n));

    if(M == NULL) {
        printf("Erro ao alocar a memória\n");
        return NULL;
    }

    for(int i = 0; i < (*n); i++) {
        M[i] = (int *)malloc(sizeof(int) * (*n));
        if(M[i] == NULL) {
            printf("Erro ao alocar a memória\n");
            return NULL;
        }
    }

    for (int i = 0; i < (*n); i++) {
        for (int j = 0; j < (*n); j++) {
            printf("Insira a posicao %dx%d: ", i, j);
            scanf("%d", &M[i][j]);
        }
    }
    
    return M;
}

void imprimirMatriz(int **m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
