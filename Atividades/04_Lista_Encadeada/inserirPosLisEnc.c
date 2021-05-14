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


// Exibicao da lista
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
  Objetivo: Inserir o item passado como parametro na posicao pos da lista.
            Caso nao haja item com a mesma chave e a posicao seja valida
            (de 0 a tamanho), o item sera inserido e a funcao retorna true.
            Caso contrario, a funcao retorna false para indicar que o
            item nao foi inserido.
 */
bool inserirNaPos(ITEM item, int posInsercao, LISTA *l)
{

    if (vazia(l))
    {
        if (posInsercao == 0)
        {
            l->cabeca = criarNo(item, NULL);
            return true;
        } else return false;
    }

    if (tamanho(l) == 1)
    {
        if (l->cabeca->item.chave == item.chave) return false;
        if (posInsercao == 0)
        {
            l->cabeca = criarNo(item, l->cabeca);
            return true;
        }
        if (posInsercao == 1)
        {
            l->cabeca->prox = criarNo(item, NULL);
            return true;
        }
    return false;      
    }
    
    NO *pAnterior = l->cabeca, *pAtual = pAnterior->prox;
    int i;

    if (posInsercao < 0 || posInsercao > tamanho(l)) return false; 

    for (i = 0; i < tamanho(l); i++)
    {
        if (pAnterior->item.chave == item.chave) return false;
        if (pAnterior->prox == NULL) break;
        pAnterior = pAtual;
        pAtual = pAnterior->prox; 
    }
    
    pAnterior = l->cabeca;
    pAtual = pAnterior->prox;

    if (posInsercao == 0)
    {
        l->cabeca = criarNo(item, pAnterior);
        return true;
    }
    
    if (posInsercao == tamanho(l))
    {
        for (i = 0; i < tamanho(l); i++)
        {
            if (pAnterior->prox == NULL)
            {
                pAnterior->prox = criarNo(item, pAtual);
                return true;
            }
            pAnterior = pAtual;
            pAtual = pAnterior->prox;
        }  
    }

    for (i = 0; i < tamanho(l); i++)
    {
        if (i == posInsercao - 1)
        {
            pAnterior->prox = criarNo(item, pAtual);
            return true;
        }
        pAnterior = pAtual;
        pAtual = pAnterior->prox;     
    } 
   return false; 
  
}


//////////////////////////////////////////////////////////////


void lerItens(LISTA *l)
{
    int n;
    int pos;
    scanf("%d", &n);

    // insere os valores n pares chave,valor
    ITEM item;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item.chave);
        scanf("%s", item.valor);
        scanf("%d", &pos);
        inserirNaPos(item, pos, l);
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
