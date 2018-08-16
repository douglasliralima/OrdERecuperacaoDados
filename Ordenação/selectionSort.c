#include <stdio.h>
#include <stdlib.h>
#define tam 100

//g++ -o selectionSort.exe selectionSort.c
//Apenas para fazer a tabela aleatória
void valores_aleatorios(int tabela[], int tamanho){
	for(int i = 0; i < tamanho; i++) tabela[i] = rand() % tamanho;
}

//Função de troca
void troca(int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

//Vamos marcar o vetor em duas partes, uma ordenada que vamos caminhar por i e outra  desordenada que vamos caminhar com j
void selectionSort(int tabela[], int tamanho){
	//Variável que vai selecionar o menor elemento
	int imenor;
	//Para cada elemento da parte ordenada começando do inicio
	for(int i = 0; i < tamanho - 1; i++){
		//Se supõe que esse elemento é o menor
		imenor = i;
		//Procuramos na parte desordenada algum elemento que seja menor que ele
		for(int j = i + 1; j < tamanho; j++){
			//Se acharmos, nossa premissa estave errada e esse elemento passa a ser aquele que merece estar na menor posição
			if(tabela[j] < tabela[imenor]){
				imenor = j;
			}
		}
		//Se verifica se o imenor foi alterado em relação a posição atual do array, se foi, vamos trocar essas posições
		if(imenor != i) troca(tabela + i, tabela + imenor);
		}
	}

int main(){
	int tabela[tam];
	valores_aleatorios(tabela, tam);
	selectionSort(tabela, tam);
	for(int i = 0; i < tam; i++) printf("%i, ", tabela[i]);
	puts("");
}