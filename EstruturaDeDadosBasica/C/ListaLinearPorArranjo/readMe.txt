Implementação simples de uma lista linear por meio de arranjos
introduzindo os seguintes comportamentos:
 1 - Checar se lista esta vazia
 2 - Criar uma Lista 
 3 - Inserir elementos no final, meio e inicio da Lista
 4 - Imprimir conteudo da Lista
 5 - Remover elementos no final, meio e inicio da Lista

 A Lista linear por meio de arranjos tem como propriedade os elementos estarem em posicao contigua na memoria
 Sendo a principal vantagem o acesso de qualquer elemento em tempo constante
 e a principal desvantagem eh a falta de flexibilidade da sua capacidade total de elementos
 que eh um fator limitador para a performace se a quantidade de itens nao eh prevista
 ou se a linguagem utilizada so permite alocaçao em tempo de compilacao

 Conteudo:
	- ListaArranjo.c
	- ListaArranjo.h
	- MainListaArranjo.c
 Compilar: 
	gcc -o Programa ListaArranjo.c MainListaArranjo.c
 
 Executar:
	./Programa < sampleInput.txt
