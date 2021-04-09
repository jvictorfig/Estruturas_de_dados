#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, menor = 1000, posicao;
    scanf("%d", &n);
    int v[n], i;

    for (i = 0; i < n; i++) scanf("%d", &v[i]);

    for (i = 0; i < n; i++)
    {
        if (v[i] < menor) 
        {
            menor = v[i];
            posicao = i;
        }
    }
    
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    return 0;
}