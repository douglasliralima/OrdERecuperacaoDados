from random import randint
'''
Acho que por enquanto é melhor fazer tudo em C com funções normal e quem sabe passar para C++
'''

def tabela_aleatoria(tamanho):
	tabela = []
	for i in range(tamanho):
		tabela.append(randint(0,1000))
	return tabela

def Troca(tabela, posAtual):
	aux = tabela[posAtual]
	tabela[posAtual] = tabela[posAtual + 1]
	tabela[posAtual + 1] = aux
	return tabela

def bubble_sort(tabela, nElem):
	emOrdem = False
	while not(emOrdem):
		emOrdem = True #Talvez ela esteja em ordem agora
		for i in range(nElem - 1):
			if(tabela[i] > tabela[i+1]):
				#Se entrou aqui não está em ordem
				tabela = Troca(tabela, i)
				emOrdem = False
	return tabela


tam = 10000
tabela = tabela_aleatoria(tam)
#print(tabela)
print(bubble_sort(tabela,tam))