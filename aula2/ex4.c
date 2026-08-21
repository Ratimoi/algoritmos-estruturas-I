#include <stdio.h>

int main() {
    int v[5] = {2, 4, 6, 8, 10};
    int *p = v;

    printf("%d\n", *p); //2
    printf("%d\n", *(p + 2)); //6
    printf("%d\n", p[3]); //8
    printf("%d\n", *p + 1); //3
    printf("%d\n", *(v + 4)); //10
}
