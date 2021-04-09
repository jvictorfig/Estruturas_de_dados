#include <stdio.h>
#include <stdlib.h>

int main(){

    int m, n, i, maiorMultiplo = 0;
    scanf("%d", &m);
    scanf("%d", &n);

    for (i = 0; i <= n; i++)
    {
        if (i % m == 0) maiorMultiplo = i; 
    }
    
    if (maiorMultiplo != 0) printf("%d\n", maiorMultiplo);
        else printf("sem multiplos menores que %d\n", n);

    return 0;
}