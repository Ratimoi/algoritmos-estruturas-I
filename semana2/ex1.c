#include <stdio.h>

int main() {
    int i = 3, j = 5;
    int *p, *q;
    
    p = &i;
    q = &j;

    int a, b, c, d;

    a = *p;
    b = *p - *q;
    c = **&p;
    d = 3 - *p / *q + 7;

    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%d\n", d);
}
