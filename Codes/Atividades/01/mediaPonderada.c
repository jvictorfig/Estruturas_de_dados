#include <stdio.h>
#include <stdlib.h>

void AnalisarSituacao(float media){

    if (media >= 9.0){
        printf("aprovado com louvor\n");
    } if (media < 9.0 && media >=7.0){
            printf("aprovado\n");
            } if (media < 7.0 && media >= 3.0){
                printf("prova final\n");
                    } if (media < 3.0){
                        printf("reprovado\n");
                    }
}

int main(){

    float n1, n2, n3, n4, media;
    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
    media = (n1 + 2 * n2 + 3 * n3 + 4 * n4) / 10;
    AnalisarSituacao(media);

    return 0;
}