#include <stdio.h>
#include <stdlib.h>

// Espaço: O(1) - Tempo: O(1)
int localizaPosicao(int *v, int n, int i) {
    if (i >= 0 && i < n) {
        return v[i];
    }

    return 0;
}


// Espaço: O(1) - Tempo: O(n)
int localizaMaior(int *v, int n) {
    if (n <= 0) {
        return 0;
    }

    int maior = v[0];

    for (int i = 1; i < n; i++) {
        if (maior < v[i]) {
            maior = v[i];
        }
    }

    return maior;
}


// Espaço: O(1) - Tempo: O(n)
int *trocarPares(int *m, int n) {
    int metade = n / 2;

    for (int i = 0; i < metade; i++) {
        int temp = m[i];
        m[i] = m[i + metade];
        m[i + metade] = temp;
    }

    return m;
}


// Espaço: O(m+n) - Tempo: O(m+n)
int *concatena(int *a, int m, int *b, int n) {
    int o = m + n;

    int *c = malloc(sizeof(int) * o);

    if (!c) {
        return NULL;
    }

    for (int i = 0; i < m; i++) {
        c[i] = a[i];
    }

    for (int i = 0; i < n; i++) {
        c[m + i] = b[i];
    }

    return c;
}


// Espaço: O(1) - Tempo: O(m+n)
void imprimePares(int *a, int m, int *b, int n) {

    for (int i = 0; i < m; i++) {
        if (a[i] % 2 == 0) {
            printf("%d ", a[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (b[i] % 2 == 0) {
            printf("%d ", b[i]);
        }
    }

    printf("\n");
}


// Espaço: O(1) - Tempo: O(n²)
int somaMatriz(int **a, int n) {
    int soma = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            soma += a[i][j];
        }
    }

    return soma;
}


// Espaço: O(1) - Tempo: O(n²)
int **transposta(int **a, int n) {

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int temp = a[i][j];

            a[i][j] = a[j][i];

            a[j][i] = temp;
        }
    }

    return a;
}


// Espaço: O(n²) - Tempo: O(n²)
int **multiplicaMatriz(int **a, int **b, int n) {

    int **c = malloc(sizeof(int *) * n);

    if (!c) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {

        c[i] = malloc(sizeof(int) * n);

        if (!c[i]) {
            for (int k = 0; k < i; k++) {
                free(c[k]);
            }

            free(c);

            return NULL;
        }

        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }

    return c;
}
