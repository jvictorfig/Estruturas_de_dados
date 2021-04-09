#include<stdio.h>
#include<stdlib.h>

int main(){

    int v1[10], v2[10], soma[10], i;
    
    scanf("%d %d %d %d %d %d %d %d %d %d", &v1[0], &v1[1], &v1[2], &v1[3], &v1[4], &v1[5], &v1[6], &v1[7], &v1[8], &v1[9]);
    scanf("%d %d %d %d %d %d %d %d %d %d", &v2[0], &v2[1], &v2[2], &v2[3], &v2[4], &v2[5], &v2[6], &v2[7], &v2[8], &v2[9]);

    for (i = 0; i < 10; i++)
    {
        soma[i] = v1[i] + v2[i];
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", soma[i]);
    }
    printf("\n");

    return 0;
}