int v[5];
int *p;

// a) p = v; --legal, representa uma operação entre ponteiros (vetor é um ponteiro)
// b) p = &v; --ilegal
// c) p = &v[0]; --legal, representa a mesma operação na opção a)
// d) v = p; --ilegal
// e) p = v + 2; --legal, os ponteiro podem realizar operações aritméticas (troca de posição)
