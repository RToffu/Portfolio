#include "PilhaArranjo.h"

/* Rafael Toffalini de Carvalho Alves */

//--> FUNCOES PILHA
Pilha * makePilha (int size_aux) {
	if (size_aux <= 0 || size_aux > PMAXLEN)
		return NULL;

	Pilha * pilha = (Pilha *)malloc(sizeof(Pilha));
	pilha->size = size_aux;
	pilha->indx = -1;
	pilha->pessoas_arr = (Pessoa **)malloc(size_aux * sizeof(Pessoa *));
	return pilha;
}
void pilhaPush (Pilha * pilha, Pessoa * obj_pessoa) {
	if (pilha->indx >= PMAXLEN-1 && pilha->size >= PMAXLEN)
		return;
	if (pilha->indx+1 >= pilha->size)
		arrayRealocation(pilha);

	pilha->indx++;
	*(pilha->pessoas_arr + pilha->indx) = obj_pessoa;
}
void pilhaPop (Pilha * pilha) {
	if (pVazia(pilha) > 0) {
		printf("PILHA ESTA VAZIA\n");
		return;
	}
	printf("(R) ");
	printPessoa(*(pilha->pessoas_arr + pilha->indx));

	freePessoa(*(pilha->pessoas_arr + pilha->indx));
	free(*(pilha->pessoas_arr + pilha->indx));
	*(pilha->pessoas_arr + pilha->indx) = NULL;
	pilha->indx--;
}
void arrayRealocation (Pilha * pilha) {
	int size_aux = (pilha->size+PINCREASE < PMAXLEN ? pilha->size+PINCREASE : pilha->size+(PMAXLEN-pilha->size));
	Pessoa ** temp = (Pessoa **)malloc(size_aux * sizeof(Pessoa *));

	for (int i = 0; i < pilha->size; i++)
		*(temp + i) = *(pilha->pessoas_arr + i);

	free(pilha->pessoas_arr);
	pilha->pessoas_arr = NULL;
	pilha->pessoas_arr = temp;
	pilha->size = size_aux;
}
void printPilha (Pilha * pilha) {
	for (int i = pilha->indx; i >= 0; i--) {
		printf("[%d]", i);
		printPessoa(*(pilha->pessoas_arr + i));
	}
}
int pVazia (Pilha * pilha) {
	if (pilha->indx < 0)
		return 1;
	return -1;
}
