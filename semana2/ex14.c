#include <stdio.h>
#include <stdlib.h>

int *intercalar(int *v1, int *v2, int n, int *n3);
int *lerVetorInt(int *n);
void imprimirVetor(int *v, int n);

int main() {
    int tamanho1, *vetor1 = lerVetorInt(&tamanho1);
    int tamanho2, *vetor2 = lerVetorInt(&tamanho2);

    if(tamanho1 != tamanho2) {
        printf("Tamanho de vetores incompativeis\n");
        return 1;
    }

    int tamanhoIntercalado , *vetorIntercalado = intercalar(vetor1, vetor2, tamanho1, &tamanhoIntercalado);

    imprimirVetor(vetorIntercalado, tamanhoIntercalado);

    free(vetor1);
    free(vetor2);
    free(vetorIntercalado);
    return 0;
}

int *intercalar(int *v1, int *v2, int n, int *n3) {
    *n3 = 2 * n;
    int *v3 = (int *)malloc(sizeof(int) * (*n3));
    if(v3 == NULL) {
        printf("Erro ao alocar a memória\n");
        return NULL;
    }

    int x = 0, y = 0;
    for(int i = 0; i < (*n3); i++) {
        if(i % 2 == 0) {
            v3[i] = v1[x];
            x++;
        } else {
            v3[i] = v2[y];
            y++;
        }
    }

    return v3;
}

int *lerVetorInt(int *n) {
    printf("Insira o tamanho do vetor: ");
    if(scanf("%d", n) != 1 || (*n) <= 0) return NULL;

    int *v = (int *)malloc(sizeof(int) * (*n));
    if(v == NULL) {
        printf("Erro ao alocar a memória\n");
        return NULL;
    }

    for(int i = 0; i < (*n); i++) {
        printf("Insira a posicao %d: ", i);
        if(scanf("%d", &v[i]) != 1) {
            free(v);
            printf("Erro ao alocar a memória\n");
            return NULL;
        }
    }

    return v;
}

void imprimirVetor(int *v, int n) {
    printf("Vetor: ");

    for(int i = 0; i < n; i++) {
        if(i == n - 1) {
            printf("%d\n", v[i]);
        } else {
            printf("%d, ", v[i]);
        }
    }
}
