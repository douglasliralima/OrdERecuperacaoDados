#include <stdio.h>
#include <stdlib.h>
#define tam 1000000

//Author: Douglas Lima

//g++ -o selectionSort.exe selectionSort.c
//Apenas para fazer a tabela aleatória
void valores_aleatorios(int tabela[], int tamanho){
	for(int i = 0; i < tamanho; i++) tabela[i] = rand() % tamanho;
}

//Função de troca
void Troca(int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}
//Melhor estudar esse código de baixo pra cima



//Para a intercalação vamos receber além de nossa tabela, uma tabela auxiliar
//O ponteiro de inicio na esquerda, na direita e o final dessa tabela 
static void Intercala( int tabela[], int aux[],
int iniEsq, int iniDir, int finalDir ){
	//Definimos essas variáveis auxiliares através do que recebemos
	int i, finalEsq, nElementos, posAux;
	finalEsq = iniDir - 1;	//Definimos onde será o fim da primeira tabela
	posAux = iniEsq;		//a posição da tabela auxiliar onde será feita a concatenação
	nElementos = finalDir - iniEsq + 1; //Definimos a quantidade de elementos na tabela da direita

	//Enquanto os nossos ponteiros permanecerem em suas tabelas
	while((iniEsq <= finalEsq) && (iniDir <= finalDir)){
		//Fazemos a verificação de qual das tabelas tem o mais valor, salvamos na auxiliar e incrementos o ponteiro	
		if(tabela[iniEsq] <= tabela[iniDir]) aux[posAux++] = tabela[iniEsq++];
		else aux[posAux++] = tabela[iniDir++];
	}

	//Caso ã tabela da direita tenha chegado ao fim, mas a esquerda não, jogamos tudo na auxiliar
	while(iniEsq <= finalEsq) aux[posAux++] = tabela[iniEsq++];
	
	//Caso a tabela da esquerda tenha chegado ao fim, mas a direita não, jogamos tudo na tabela auxiliar
	while(iniDir <= finalDir) aux[posAux++] = tabela[iniDir++];
	
	//Agora copiamos a tabela auxiliar na tabela original
	for(i = 0; i < nElementos; i++,finalDir--) tabela[finalDir] = aux[finalDir];
}


//recebemos nossa tabela e um espaço de memória auxiliar, junto com os ponteiros da esquerda e da direita
static void MSort(int *tabela, int *aux, int esquerda, int direita){
	//Criamos a variável "centro" que vai falar o limite entre a tabela esquerda e direita
	int centro;
	//Esse if é nossa condição de parada, quando esquerda == direita, só vamos ir retornando e n dividiremos mais
	if(esquerda < direita) {
		//Pegamos o centro
		centro = (esquerda + direita)/2;
		//Vamos dividindo a tabela da esquerda
		MSort(tabela, aux, esquerda, centro);
		//Vamos dividindo a tabela da direita
		MSort(tabela, aux, centro + 1, direita);
		
		//Quando as duas funções retornarem, com uma tabela unitária ou maior, vamos intercalar
		Intercala(tabela, aux, esquerda, centro + 1, direita);
	}
}

void MergeSort(int tabela[], int nElem){
	int *aux;
	//Alocamos espaço para a tabela auxiliar com a função malloc, fazemos isso para reservar um endereço do tamanho de nossa tabela
	aux = (int *) malloc(nElem*sizeof(int)); //Em C++ esse cast é necessário, se voce for compilar como gcc, n precisa
			//ASSEGURA(aux, ERRO: Impossivel alocar tabela auxiliar); Não entendi que raio de função é essa
	
	//MSort vai lá fazer o verdadeiro trabalho
	MSort(tabela, aux, 0, nElem - 1);

	/* Libera o espaço ocupado pela tabela auxiliar */
	free(aux);
}



int main(){
	int tabela[tam];
	valores_aleatorios(tabela, tam);
	MergeSort(tabela, tam);
	for(int i = 0; i < tam; i++) printf("%i, ", tabela[i]);
	puts("");
}