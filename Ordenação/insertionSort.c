#include <stdio.h>
#include <stdlib.h>
#define tam 100000

//g++ -o selectionSort.exe selectionSort.c
//Apenas para fazer a tabela aleatória
void valores_aleatorios(int tabela[], int tamanho){
	for(int i = 0; i < tamanho; i++) tabela[i] = rand() % tamanho;
}

//copia no endereço da direita(posição onde antes era a do elemento na variável auxiliar)e se repete para cada elemento maior
//Quando chegar em um elemento menor, copia o valor da variável no elemento da direita 
void insertionSort(int tabela[], int tamanho){
	int aux, j;
	//A partir do segundo elemento, salvar seu valor em uma variável auxiliar
	for(int i = 1; i < tamanho; i++){
		aux = tabela[i];
		//Depois olhamos cada elemento da esquerda é vemos se ele é maior ou se chegamos depois do começo do array
		for (j = i - 1; j >= 0 && aux < tabela[j]; j--){
			//Cada vez que essa condição for correspondida, copiamos na direita, o elemento da esquerda
			tabela[j + 1] = tabela[j];
		}
		//Usando a variável j que está na posição do menor elemento ou depois da origem, colamos na direita
		tabela[j + 1] = aux;
	}
}




int main(){
	int tabela[tam];
	valores_aleatorios(tabela, tam);
	insertionSort(tabela, tam);
	for(int i = 0; i < tam; i++) printf("%i, ", tabela[i]);
	puts("");
}