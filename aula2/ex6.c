#include <stdio.h>

int soma(int *v, int n);

int main() {
    int vetor[5] = {10, 20, 30, 40, 50};
    int tamanho = 5;

    int resultado = soma(vetor, tamanho);

    printf("%d", resultado);

    return 0;
}

int soma(int *v, int n) {
    int resultado = 0;

    for(int i = 0; i < n; i++) {
        resultado += v[i];
    }

    return resultado;
}
