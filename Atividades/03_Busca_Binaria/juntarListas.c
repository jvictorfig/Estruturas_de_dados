#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef int TIPOCHAVE;

typedef struct {
	TIPOCHAVE chave;
	char valor[100];
} ITEM;

typedef struct{
	ITEM itens[MAX];
	int tamanho;
} LISTA;


///////////////////////////////////////////////////////////////


// Inicializa a lista deixando-a pronta para ser utilizada.
void inicializar(LISTA *l)
{
    l->tamanho = 0;
}

// Retornar o tamanho da lista sequencial
int tamanho(LISTA *l)
{
    return l->tamanho;
}


// Retorna true se a lista esta cheia (Tamanho = MAX)
bool cheia(LISTA *l)
{
    return tamanho(l) == MAX;
}


// Retorna true se a lista esta vazia (Tamanho = 0)
bool vazia(LISTA *l)
{
    return tamanho(l) == 0;
}


/*
  Objetivo: Executa uma busca binaria na lista. 
            Depende da lista estar ordenada.
            Retorna a posicao (indice) do item (no) na lista que possui chave
            igual a passada como parametro.
            Caso nao encontre, retorna o valor -1.
*/
int buscaBin(TIPOCHAVE ch, int inicio, int fim, ITEM *itens)
{
    while (inicio <= fim)
    {
        int meio = ((inicio + fim) / 2); // calcula a posicao do meio
        if (itens[meio].chave == ch) 
            return meio; // achou
        else
        {
            if (itens[meio].chave < ch) 
                inicio = meio + 1; // concentra a busca na parte da direita
            else 
                fim = meio - 1; // concentra a busca na parte da esquerda
        }
    }
    return -1; // nao achou
}


// Simplifica a busca e permite escolher o tipo de busca
int busca(TIPOCHAVE ch, LISTA *l)
{
    //return buscaSeq(ch, 0, l->tamanho - 1, l->itens);
    return buscaBin(ch, 0, l->tamanho - 1, l->itens);
    //return buscaBinRec(ch, 0, l->tamanho - 1, l->itens);
}


// Retornar o n-esimo elemento da lista sequencial
// Pre-condicao: 0 <= n < tamanho 
ITEM enesimo(int n, LISTA *l)
{
    if (n >= 0 && n < tamanho(l)) 
        return (l->itens[n]);
    else 
        exit(EXIT_FAILURE);
}


/*
 Objetivo: Move para uma posicao para direita todos os elementos a partir
           da posicao pos, comecando a copia da posicao tamanho - 1 (final)
           para tamanho e terminando ate chegar a copiar para pos + 1 o
           item contido em pos.
*/ 
void moverParaDireita(int pos, LISTA *l)
{
    for (int i = l->tamanho; i > pos; i--)
        l->itens[i] = l->itens[i-1];
}


/*
  Objetivo: Inserir o item passado como parametro na posicao i da lista.
            Caso a lista nao esteja cheia e a posicao seja valida, o item
            sera inserido e a funcao retorna true. Caso contrario, a funcao
            retorna false para indicar que o item nao foi inserido.
 */
bool inserirNaPos(ITEM item, int i, LISTA *l)
{
	// A posicao tem que estar entre 0 e MAX-1 e ate o tamanho atual
	if ((tamanho(l) >= MAX) || (i < 0) || (i > tamanho(l)))
		return false; // lista cheia ou indice invalido
	// Se for inserido no meio, e necessario abrir espaco para o item
	if ((tamanho(l) > 0) && (i < tamanho(l)))
        moverParaDireita(i, l);

	l->itens[i] = item;
	l->tamanho++;
	return true;
}



/*
 Objetivo: Inserir em uma lista ordenada o item passado e garantir
           que nao havera duplicacao. 
           Esta versao nao usa a busca sequencial (menos eficiente).
*/
bool inserirNaOrdem(ITEM item, LISTA *l)
{
    if (cheia(l)) 
        return false; // lista cheia

    int i = 0;
    
    // Faz uma busca sequencial ate o ponto correto de insercao
    // ou chegar ao final da lista
    while ((l->itens[i].chave < item.chave) && i < tamanho(l)) i++;
    
    // Se encontrou a chave e nao extrapolou os limites da lista
    if ((l->itens[i].chave == item.chave) && (i < tamanho(l)))
        return false;
    else 
        return inserirNaPos(item, i, l);
}


// Exibicao da lista sequencial
void exibirLista(LISTA *l)
{
    int i;
	for (i = 0; i < l->tamanho; i++)
		printf("(%d,%s)", l->itens[i].chave, l->itens[i].valor);
}


// Destruicao da lista sequencial
void destruir(LISTA *l)
{
	l->tamanho = 0;
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

void imprimirLista(LISTA *l)
{
    printf("Tamanho = %d\n", tamanho(l));
    exibirLista(l);
    printf("\n");
}

///////////////////////////////////////////////////////////////

/*
 Objetivo: A partir das listas l1 e l2, fazer a juncao dos
           valores contidos em l1 em l2 na lista l_juncao,
           mantendo a ordem final entre os valores.
           A funcao deve inicializar l_juncao.
           A soma dos tamanhos de l1 e l2 tem que ser menor
           que a capacidade da lista.
           Caso tenha sucesso, retorna true e o parametro
           l_juncao contem a lista intercalada com os valores.
           Caso haja algum item com chave igual nas listas l1
           e l2, a funcao deve retornar false e l_juncao deve
           ser destruida (usando a funcao destruir).

*/
bool juntar(LISTA *l1, LISTA *l2, LISTA *l_juncao)
{
    int i, j;
    inicializar(l_juncao);

    //casos vazia
    if (vazia(l1) && vazia(l2))
    {
        return true;
    }
    if (vazia(l1))
    {
        //printf("l1 vazia\n");
        *l_juncao = *l2;
        return true;
    }
    if (vazia(l2))
    {
        printf("l1 vazia\n");
        *l_juncao = *l1;
        return true;
    }
    
    //verificar se a l_juncao é maior que o tamanho máximo permitido
    if (tamanho(l1) + tamanho(l2) > MAX) return false;

    //Verificar se existem chaves iguais
    for (i = 0; i < tamanho(l1); i++)
    {
        for (j = 0; j < tamanho(l2); j++)
        {
            if (l1->itens[i].chave == l2->itens[j].chave){
                return false;
            }
        }
        
    }

    //Juncao das listas
    for (i = 0; i < tamanho(l1); i++)
    {
        inserirNaOrdem(l1->itens[i], l_juncao);
    }
    for (i = 0; i < tamanho(l2); i++)
    {
        inserirNaOrdem(l2->itens[i], l_juncao);
    }
    return true;
  
}

///////////////////////////////////////////////////////////////

int main(){
	LISTA l1, l2, lr;
	
	inicializar(&l1);
    inicializar(&l2);
    
    lerItens(&l1);
    lerItens(&l2);

    imprimirLista(&l1);
    imprimirLista(&l2);
    
    if (juntar(&l1, &l2, &lr))
    {
        printf("Juncao efetuada\n");
        imprimirLista(&lr);
    }
    else
        printf("Impossivel fazer a juncao\n");
	

	getchar();
	return 0;
}