#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char frase[100];
    int i, j = 0;

    fgets(frase, 100, stdin);

    for (i = 0; i < sizeof(frase); i++){
        if (frase[i] == NULL)
        {
            break;
        }
        
        if (frase[i] == 'a' || frase[i] == 'A')
        {
            j++;
        }
        
    }
    printf("%d\n", j);
    

    return 0;
}