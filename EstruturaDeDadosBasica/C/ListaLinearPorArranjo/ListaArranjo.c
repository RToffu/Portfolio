#include "ListaArranjo.h"

/* Rafael Toffalini de Carvalho Alves */

//--> FUNCOES LISTA
Lista * makeLista (int size_aux) {
	if (size_aux <= 0 || size_aux > LMAXLEN)
		return NULL;
	
	Lista * lista = (Lista *)malloc(sizeof(Lista));
	lista->size = size_aux;
	lista->indx = -1;
	lista->pessoas_arr = (Pessoa **)malloc(size_aux*sizeof(Pessoa *));
	return lista;
}
int insertLista (Lista * lista, Pessoa * obj_pessoa) {
	if (lista->indx >= LMAXLEN-1 && lista->size >= LMAXLEN)
		return -1;

	if (lista->indx+1 >= lista->size) 
		arrayRealocation(lista);
	
	lista->indx++;
	*(lista->pessoas_arr + lista->indx) = obj_pessoa;
	return 1;
}
int insertListaPos (Lista * lista, Pessoa * obj_pessoa, int position) {
	if (lista->indx >= LMAXLEN-1 && lista->size >= LMAXLEN)
		return -1;
	
	if (position > lista->indx || position > lista->size)
		return -1;

	if (lista->indx+1 >= lista->size)
		arrayRealocation(lista);

	lista->indx++;
	printf("(I - %d) ", position);
	printPessoa(obj_pessoa);
	shiftListaRight(lista, position);
	*(lista->pessoas_arr + position) = obj_pessoa;
	return 1;
}
void shiftListaRight (Lista * lista, int position) {
	for (int i = lista->indx; i > position; i--) 
		*(lista->pessoas_arr + i) = *(lista->pessoas_arr + i-1);
}
void removeLista (Lista * lista) {
	if (listaVazia(lista) > 0) {
		printf("A LISTA ESTA VAZIA\n");
		return;
	}
	printf("(R) ");
	printPessoa(*(lista->pessoas_arr + lista->indx));
	
	freePessoa(*(lista->pessoas_arr + lista->indx));
	free(*(lista->pessoas_arr + lista->indx));
	*(lista->pessoas_arr + lista->indx) = NULL;
	lista->indx--;		
}
void removeListaPos (Lista * lista, int position) {
	if (listaVazia(lista) > 0) {
		printf("A LISTA ESTA VAZIA\n");
		return;
	}
	printf("(R - %d) ", position);
	printPessoa(*(lista->pessoas_arr + position));
	freePessoa(*(lista->pessoas_arr + position));
	free(*(lista->pessoas_arr + position));
	*(lista->pessoas_arr + position) = NULL;
	shiftListaLeft(lista, position);
	lista->indx--;
}
void shiftListaLeft (Lista * lista, int position) {
	for (int i = position; i < lista->indx; i++) 
		*(lista->pessoas_arr + i) = *(lista->pessoas_arr + i+1);


}
void arrayRealocation (Lista * lista) {
	int size_aux = ( lista->size+LINCREASE < LMAXLEN ? lista->size+LINCREASE : lista->size+(LMAXLEN-lista->size) );
	Pessoa ** temp = (Pessoa **)malloc(size_aux*sizeof(Pessoa *)); //caso size seja maior q 90 e menor q 100 calcula 
								       //o quanto a lista pode aumentar
	for (int i = 0; i < lista->size; i++) 
		*(temp + i) = *(lista->pessoas_arr + i);
	
	free(lista->pessoas_arr);
	lista->pessoas_arr = NULL;
	lista->pessoas_arr = temp;
	lista->size = size_aux;
}
int listaVazia (Lista * lista) {
	if (lista->indx < 0)
		return 1;
	return -1;
}
void printLista (Lista * lista) {
	for (int i = 0; i <= lista->indx; i++) {
		printf("[%d] ", i);
		printPessoa(*(lista->pessoas_arr + i));
	}
}
