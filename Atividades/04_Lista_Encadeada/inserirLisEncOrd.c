#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    char valor[100];
} ITEM;

typedef struct estrutura
{
    ITEM item;
    struct estrutura *prox;
} NO;

typedef struct
{
    NO* cabeca;
} LISTA;



// Inicializa a lista deixando-a pronta para ser utilizada.
void inicializar(LISTA *l)
{
    l->cabeca = NULL;
}


// Cria um novo no com o item passado e tendo NULL como prox
NO* criarNo(ITEM item, NO *prox)
{
    NO* pNovo = (NO*) malloc(sizeof(NO));
    pNovo->item = item;
    pNovo->prox = prox;
    return pNovo;
}


// Retornar o tamanho da lista
int tamanho(LISTA *l)
{
    NO* p = l->cabeca;
    int tam = 0;
    while (p)  // p != NULL
    {
        tam++;
        p = p->prox;
    }
    return tam;
}


// Retorna true se a lista esta vazia (Cabeca = NULL)
bool vazia(LISTA *l)
{
    return l->cabeca == NULL;
}


// Exibicao da lista sequencial
void exibirLista(LISTA *l)
{
    NO* p = l->cabeca;
    while (p)  // p != NULL
    {
        printf("(%d,%s)", p->item.chave, p->item.valor);
        p = p->prox;
    }
}


// Liberacao das variaveis dinamicas dos nos da lista, iniciando da cabeca
void destruir(LISTA *l)
{
    NO* atual = l->cabeca;
    while (atual) {
        NO* prox = atual->prox; // guarda proxima posicao
        free(atual);            // libera memoria apontada por atual
        atual = prox;
    }
    l->cabeca = NULL; // ajusta inicio da lista (vazia)
}


void imprimirLista(LISTA *l)
{
    printf("Tamanho = %d\n", tamanho(l));
    exibirLista(l);
    printf("\n");
}


/////////////////////////////////////////////////////

/*
 Objetivo: Inserir em uma lista ordenada o item passado e garantir
           que nao havera duplicacao.
*/
bool inserirNaOrdem(ITEM item, LISTA *l)
{

    if (vazia(l))
    {
        //printf("Ainda ta vazia!\n");
        l->cabeca = criarNo(item, NULL);
        //printf("criou!\n");
        return true;
    }

    NO *pAnterior = l->cabeca, *pProximo = l->cabeca->prox, *pAtual;
    int i;

    for (i = 0; i < tamanho(l); i++)
    {
        pAtual = pAnterior->prox;
        
        if (pAnterior->item.chave < item.chave)
        {
            //printf("Entrou!\n");
            if (pAtual == NULL)
            {
                //printf("pAtual Nulo!\n");
                pAnterior->prox = criarNo(item, NULL);
                return true;
            } else  if (pAtual->item.chave > item.chave)
                    {
                        //printf ("Atual nao nulo e chave maior!\n");
                        pAnterior->prox = criarNo(item, pAtual);
                        pAtual = pAnterior->prox;
                        pAnterior = pAtual;
                        return true;
                    }
        } else if (pAnterior->item.chave == item.chave)
        {
            //printf("Essa chave ja existe!\n");
            return false;
        } else if (pAnterior->item.chave > item.chave)
        {
            //printf("Chave Maior!\n");
            l->cabeca = criarNo(item, pAnterior);
            return true;
        }
        
        
        pAnterior = pAtual;
        
        
    }
    //printf("Nem Entrou!\n");
    return false;
    

  
}
//////////////////////////////////////////////////////////////


void lerItens(LISTA *l)
{
    int n;
    scanf("%d", &n);

    // insere os valores n pares chave,valor
    ITEM item;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item.chave);
        scanf("%s", item.valor);
        inserirNaOrdem(item, l);
    }
}


int main(){
  LISTA l;
  ITEM item;

  inicializar(&l);

  lerItens(&l);
  imprimirLista(&l);
    
  lerItens(&l);
  imprimirLista(&l);

  destruir(&l);
  return 0;
}
