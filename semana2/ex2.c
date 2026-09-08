#include <stdio.h>

int main() {
    int i = 3, j = 5;
    int *p, *q;
    
    p = &i;
    q = &j;

    *p = *q; // i=5 , j=5 , p=&i, q=&j
    p = q; // i=5 , j=5 , p=&j, q=&j
    *p = *p + *q; // i=8 , j=5 , p=&i, q=&j
    q = &i; *q = 100; // i=3 , j=100 , p=&i, q=&i
}
