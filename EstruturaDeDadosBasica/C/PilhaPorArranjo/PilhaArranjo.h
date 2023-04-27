#ifndef PILHAARRANJO_H
#define PILHAARRANJO_H
/* Rafael Toffalini de Carvalho Alves */

#include "Pessoa.h"

#define PMAXLEN 100
#define PINCREASE 10

//--> STRUCT PILHA
typedef struct Pilha {
	int size;
	int indx;
	Pessoa ** pessoas_arr;
}Pilha;
//--> HEADER PILHA
int pVazia (Pilha *);
Pilha * makePilha (int);
void pilhaPush (Pilha *, Pessoa *);
void pilhaPop (Pilha *);
void printPilha (Pilha *);
void arrayRealocation (Pilha *);

#endif //PilhaArranjo.h
