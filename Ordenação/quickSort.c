#include <stdio.h>
#include <stdlib.h>
#define tam 100

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

//Pegamos inicialmente nossos limites inferior e superior, junto com a tabela
void quickSort(int tabela[], int inf, int sup){
	//Vamos separar os ponteiros de posição do pivo, da esquerda e da direita
	int esq, dir, iPivo;

	if(inf >= sup) return; //Tabela chegou ao ponto de corte = 1 registro

	//Vamos fazer a implementação que o pivo é sempre o primeiro elemento da tabela
	iPivo = inf;

	//Vamos agora repartir a tabela, settando os ponteiros e dizendo que esse for só vai parar quando o dir passar o esq ou vice-versa
	for(esq = inf, dir = sup; esq < dir; ){
		//Esquanto os elementos elementos da primeira metade da tabela forem menores do que o pivô, incrementa-se o índice esquerdo
		//Ou quando vai para a direita
		while (tabela[esq] <= tabela[iPivo] && esq < sup) esq++;

		//Mesma coisa para o direito	
		//while(tabela[dir] >= tabela[iPivo]) dir--; //Não permite a execução
		while(tabela[dir] >= tabela[iPivo] && dir > inf) dir--;

		//Trocamos de lugar agora se os elementos da esq e dir acharam um bloqueio, logo não se ultrapassando
		if (esq < dir) Troca(tabela + esq, tabela + dir);
	}

	//Pronto, tá tudo repartido e agora trocamos a posição do pivo com o ponteiro direito
	Troca(tabela + iPivo, tabela + dir);

	//Agora fazemos a chamada recursiva na esquerda, passando a tabela, da origem até a atual posição do ponteiro da direita
	quickSort(tabela, inf, dir - 1); //Fazemos dir - 1, pois é nessa posição que atualmente se encontra o pivo

	//E na direita, mandamos a posição esq e o limite superior da tabela
	quickSort(tabela, dir + 1, sup); //Acho que se substituir dir + 1, por esq, também dá certo
}

int main(){
	int tabela[tam];
	valores_aleatorios(tabela, tam);
	quickSort(tabela, 0, tam - 1);
	for(int i = 0; i < tam; i++) printf("%i, ", tabela[i]);
	puts("");
}