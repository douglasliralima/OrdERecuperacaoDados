#include <stdio.h>
#include <stdlib.h>
#define tam 100

//Dá para fazer mini funções assim, elas serão úteis para fazer nossos calculos
#define FILHO_E(x) (2*(x) + 1)
#define FILHO_D(x) (2*(x) + 2)
#define PAI(x) (((x) - 1)/2)
#define TAMANHO_INICIAL 10 

//Vamos fazer aqui um heap de mínimo, ou um heap ascendente

typedef int tNoHeap; //Vai simbolizar o nosso nó no heap

typedef struct
{

	tNoHeap *itens; //Array com os elementos do heap
	int capacidade;
	int nItens; //Quantos elementos atualmente tem no heap

}tHeap;

//Professor fez uma parada que eu não entendi, então eu fiz essa função aqui que compara dois elementos
static int Compara(int *a, int *b){
	return *a < *b;
}


//-----------------------------------------------------Funções Secundárias--------------------------------------------------------
//Vamos primeiro defnir a função que pega um ponteiro de heap e transfere o heap instânciado
tHeap *IniciaHeap(tHeap *heap){
	//Primeira coisa que a gente faz é definir o tamanho máximo do HEAP, assim como reservar o espaço de memória do seu array
	heap->capacidade = TAMANHO_INICIAL;
	heap->nItens = 0;
	heap->itens = calloc(TAMANHO_INICIAL, sizeof(tNoHeap));
	return heap;
}

//Outra função padrão tbm é para destruir o interior do heap, esvazia-lo
void DestroiHeap(tHeap *heap)
{
	free(heap->itens); //Libera o espaço reservado do heap
	heap->nItens = 0; //Diz q agora o heap tá zerado
}

static int HeapCheio(tHeap *heap)//Antigamente tinha const, eu tirei pq n entendi a necessidade
{
	return heap->nItens == heap->capacidade;
}

static tHeap *RedimensionaHeap(tHeap *heap)
{
	//Basicamente nos realocamos o espaço do heap para o seu dobro, pode dar erro, mas sua conta e risco
	heap->capacidade *= 2;
	heap->itens = realloc(heap->itens,heap->capacidade*sizeof(tNoHeap));
	return heap;
}

int HeapVazio(const tHeap *heap)
{
 return !heap->nItens;//Se houver algum número, volta False, se não houver nenhum, volta True
}

void Troca(int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

//Raiz é o menor elemento
tNoHeap ObtemMinimo(const tHeap *heap)
{
	return heap->itens[0];
}

//A função compara elemento do professo é escrotona, mas permite
//Retornar 0 se e1 = e2
//Valor maior que 0, se o primeiro for maior que o segundo
//Valor menor que 0, se o contrário
int ComparaElementos(const void *e1, const void *e2){
	return *(int *)e1 - *(int *)e2;
}
//------------------------------------------------------Funções principais--------------------------------------------------------


//Essa função será aquela que caso o heap esteja desordenado, o deixara novamente bonitinho
//Teremos aqui o heap e também o indice por onde queremos ordenar
static void OrdenaHeap(tHeap *heap, int indice){
	int iEsq = FILHO_E(indice); //Primeiro calculamos o filho da esquerda
	int iDir = FILHO_D(indice); //Depois o da direita
	//Vamos começar nossa comparação pelo pressuposto de que o pai é o menor msm
	int iMenor = indice;

	//Agora comparamos de fato, se o pai for maior que o indice da esquerda
	if (&heap->itens[iEsq] < &heap->itens[indice]) iMenor = iEsq;
	//Vemos então se o pai é maior que o indice da direita
	if(&heap->itens[iDir] < &heap->itens[indice]) iMenor = iDir;

	//Se o nó for menor que seus filhos, trocamos de posição com o menor deles e o iMenor foi alterado
	if(iMenor != indice){
		Troca(&heap->itens[indice], &heap->itens[iMenor]);
		//Se entrar aqui, logo precisamos fazer a função recursiva para reordenar embaixo, na posição onde houve a troca
		OrdenaHeap(heap, iMenor);
	}

}

void InsereEmHeap(tHeap *heap, tNoHeap item)
{
	/* Se o array que suporta o heap */
	/* estiver repleto, redimensiona-o */
	if(HeapCheio(heap)) RedimensionaHeap(heap);
	/* Acrescenta o novo elemento ao final do array */
	 /* e incrementa o número de elementos no heap */
	heap->itens[heap->nItens] = item;
	heap->nItens++;
	/* Reordena o heap se for necessário */
	//Essa função vai incrementar enquanto i for maior que 0 e a função não retornar um valor falso
	//Basicamente aqui a gente tá voltando no array, sempre comparando com o pai
	for (int i = heap->nItens - 1; i && Compara( &heap->itens[PAI(i)],&heap->itens[i]) > 0; ) {
		Troca( &heap->itens[i], &heap->itens[PAI(i)]);
		i = PAI(i);
	}
}

/*
*Vai receber o heap onde acontece a remoção apenas
*/

tNoHeap RemoveMin(tHeap *heap)
{
	tNoHeap menorElemento;
	//Primeira coisa que a gente faz é ver se o heap não está vazio
	if(HeapVazio(heap)){
		printf("Heap vazio");
		exit(0);
	}
	//Primeira coisa nos pegamos a raiz, local onde em tese está o menor elemento
	menorElemento = heap->itens[0];
	
	//Agora vamos seguir aquele algoritmo, onde a gente coloca o último elemento na raiz
	heap->itens[0] = heap->itens[heap->nItens - 1];
	//Vamos fazendo a percolação descendente
	OrdenaHeap(heap, 0);
	return menorElemento;
}

//----------------------------------------Teste do Programa------------------------------------------------



//Apenas para fazer a tabela aleatória
void valores_aleatorios(tHeap *tabela, int tamanho){
	for(int i = 0; i < tamanho; i++) InsereEmHeap(tabela, rand() % tamanho);
}

int main(){
	tHeap *tabela;
	tabela = IniciaHeap(tabela);
	valores_aleatorios(tabela, tam);
	for(int i = 0; i < tam; i++) printf("%i, ", RemoveMin(tabela));
	puts("");
}

