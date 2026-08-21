#include <stdio.h>

void inverter(int *v, int n);

int main() {
    int vetor[5] = {10, 20, 30, 40, 50};
    int tamanho = 5;

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    
    inverter(vetor, tamanho);
    
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}

void inverter(int *v, int n) {
    int i = 0;
    int j = n -1;

    while (i < j) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;

        ++i;
        --j;
    }
}
