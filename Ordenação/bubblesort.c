#include <stdio.h>
#include <stdlib.h>
#define tam 100

void valores_aleatorios(int tabela[], int tamanho){
	for(int i = 0; i < tamanho; i++) tabela[i] = rand() % tamanho;
}

void troca(int tabela[], int posAtual){
	int aux = tabela[posAtual];
	tabela[posAtual] = tabela[posAtual + 1];
	tabela[posAtual + 1] = aux;
}

void BubbleSort(int tabela[], int tamanho){
	int emOrdem = 0;
	while(!emOrdem){
		emOrdem = 1;
		for(int i = 0; i < tamanho - 1; i++){
			if(tabela[i] > tabela[i + 1]){
				emOrdem = 0;
				troca(tabela, i);
			}
		}
	}
}

int main(){
	int tabela[tam];
	valores_aleatorios(tabela, tam);
	BubbleSort(tabela, tam);
	for(int i = 0; i < tam; i++) printf("%i, ", tabela[i]);
	puts("");
}