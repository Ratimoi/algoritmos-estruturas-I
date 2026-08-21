#include <stdio.h>

void min_max(int *v, int n, int *min, int *max);

int main() {
    int vetor[6] = {10, 20, 30, 40, 50, 60};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    
    for (int i = 0; i < tamanho; i += 2) {
        troca_vizinhos(&vetor[i], &vetor[i + 1]);
    }

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}

void min_max(int *v, int n, int *min, int *max)  {

}
