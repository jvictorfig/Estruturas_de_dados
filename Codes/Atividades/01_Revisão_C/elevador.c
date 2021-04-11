#include <stdio.h>
#include <stdlib.h>

int main(){

    int N, C, i, j = 0, S, E, pessoas = 0;
    scanf("%d %d", &N, &C);
    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &S, &E);
        pessoas = pessoas + E - S;
        if (pessoas > C) j = 1;
    }

    if (j == 1) printf("S\n");
        else printf("N\n");
    
    return 0;

}