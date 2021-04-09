#include<stdio.h>
#include<stdlib.h>

int main(){

    int pii[45], piii[30], i, j;

    for (i = 0; i < 45; i++)
    {
        scanf("%d ", &pii[i]);
    }

    for (j = 0; j < 30; j++)
    {
        scanf("%d ", &piii[j]);
    }
    
    for (i = 0; i < 45; i++)
    {
        for (j = 0; j < 30; j++)
        {
            if (pii[i] == piii[j])
            {
                printf("%d ", pii[i]);
            }
        
        }
    }
    printf("\n");
    
    return 0;
}