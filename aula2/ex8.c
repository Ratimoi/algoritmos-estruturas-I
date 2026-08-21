#include <stdio.h>

void min_max(int *v, int n, int *min, int *max);

int main() {
    int vetor[6] = {10, 20, 30, 40, 50, 60};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int *min, *max;
    
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    
    min_max(vetor, tamanho, min, max);
    
    printf("%d %d\n", *min, *max);

    return 0;
}

void min_max(int *v, int n, int *min, int *max)  {
    *min = v[0];
    *max = v[0];
    for (int i = 1; i < n; i++) {
        if (*max < v[i]) {
            *max = v[i];
        } else if (*min > v[i]) {
            *min = v[i];
        }
    }
}
