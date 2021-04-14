#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char pais1[20], pais2[20];
    int pts1, pts2, sg1, sg2, g1, g2, i;

    fgets( pais1, 20, stdin);
    for (i = 0; i < 20; i++)
    {
        pais1[i] = tolower(pais1[i]);
    }
    scanf("%d", &pts1);
    scanf("%d", &sg1);
    scanf("%d", &g1);

    scanf("%s", pais2);
    for (i = 0; i < 20; i++)
    {
        pais2[i] = tolower(pais2[i]);
    }
    scanf("%d", &pts2);
    scanf("%d", &sg2);
    scanf("%d", &g2);

    if (pts1 == pts2)
    {
        if (sg1 == sg2)
        {
            if (g1 == g2)
            {
                printf("EMPATE");
            }   else {
                    if (g1 > g2) printf("%s", pais1);
                        else printf("%s", pais2);    
                } 
        }   else {
                if (sg1 > sg2) printf("%s", pais1);
                    else printf("%s", pais2);
            }
    }   else {
            if (pts1 > pts2) printf("%s", pais1);
                else printf("%s", pais2);
        }
    

    return 0;
}