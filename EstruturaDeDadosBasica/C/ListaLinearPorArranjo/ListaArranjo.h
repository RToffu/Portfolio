#ifndef LISTAARRANJO_H
#define LISTAARRANJO_H
/* Rafael Toffalini de Carvalho Alves */

#include "Pessoa.h"

#define LMAXLEN 100 //TAMANHO MAXIMO DA LISTA
#define LINCREASE 10 //QUANTO O ARRAY DE PESSOAS AUMENTA CASO CHEIO

//--> STRUCT LISTA
typedef struct Lista { // Lista linear por meio de arranjos
	int size; // capacidade atual da lista
	int indx; // Apontador para ultimo elemento da lista
	Pessoa ** pessoas_arr; //Ponteiro duplo para alocaçao em memoria heap
}Lista;
//--> HEADER LISTA
int listaVazia (Lista *); // checa se a Lista esta vazia
Lista * makeLista (int); // Retorna um poiteiro tipo Lista
int insertLista (Lista *, Pessoa *); // Insere um registro Pessoa no final(posicao de indx) da Lista
int insertListaPos (Lista *, Pessoa *, int); // Insere um Registro Pessoa dada a posicao
void shiftListaRight (Lista *, int); // Funcao auxiliar de insertListaPos para mover os elementos
				     // a direita da posicao que recebe novo elemento preservando 
				     // os itens originais da lista
void removeLista (Lista *); // remove ultimo item da lista
void removeListaPos (Lista *, int); // remove um Registro Pessoa dada a posicao
void shiftListaLeft (Lista *, int); // Funcao auxiliar de removeListaPos com operacao inversa de shiftListaRight
void arrayRealocation (Lista *); // Quando a lista atinge sua capacidade maxima esta funcao realoca um novo espaco
				 // em memoria para a lista e copia os elementos da lista original para a nova lista
void printLista (Lista *); //imprime o conteudo da lista

#endif //ListaArranjo.h
