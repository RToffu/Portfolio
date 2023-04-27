#include <stdlib.h>
#include <stdio.h>
#include "ListaArranjo.h"

//--> FUNCOES PESSOA
Pessoa * makePessoa (char * str, int size) { //funcao recebe string contendo toda a informacao de Pessoa
	//first_name, last_name, age, email
	char * temp = (char *)malloc(100*sizeof(char)); //string auxiliar para fazer a leitura da String do parametro
	Pessoa * pessoa = (Pessoa *)malloc(sizeof(Pessoa)); //pessoa q sera retornada pela funcao
	enum pessoa_case ts_case = 0; //enum para melhor legibilidade
	int i, indx, tog; //i para percorres str, indx para percorrer temp, e tog para separar a leitura de cada atributo
	i = 1; //i comeca em 1 pois o primeiro caractere eh aspas
	while (i < size) {
		indx = 0;
		tog = 1;
		while (tog > 0) { //enquanto os caracteres forem diferente de aspas temp recebe conteudo de str
			if (*(str + i) == '"')
				tog *= -1;
			else
				*(temp + indx++) = *(str + i++);
		}
		*(temp + indx) = '\0'; //caractere nulo no final de temp
		switch (ts_case) {
			case F_NAME: 
				if (indx > 0)
					pessoa->first_name = toPessoaChar(temp, indx);
				else 
					pessoa->first_name = NULL;
				break;
			case L_NAME:
				if (indx > 0)
					pessoa->last_name = toPessoaChar(temp, indx);
				else
					pessoa->last_name = NULL;
				break;
			case P_AGE:
				if (indx > 0)
					pessoa->age = toPessoaInt(temp, indx);
				else 
					pessoa->age = -1;
				break;
			case P_EMAIL:
				if (indx > 0)
					pessoa->email = toPessoaChar(temp, indx);
				else
					pessoa->email = NULL;
				break;
			default:
				break;
		}
		i += 3;
		ts_case++; //passa para a atribuicao do prox atributo
	}
	free(temp);
	temp = NULL;
	return pessoa;
}
void printPessoa (Pessoa * pessoa) {
	printf("%s %s", pessoa->first_name, pessoa->last_name);
	printf(" Age: %d", pessoa->age);
	printf(" E-mail: %s", pessoa->email);
	printf("\n");	
}
char * toPessoaChar (char * str, int size) { //recebe temp e a copia para um novo endereco para ser alocada em Pessoa
	char * aux = (char *)malloc(size+1*sizeof(char));
	*(aux + size) = '\0';
	
	for (int i = 0; i < size; i++) 
		*(aux + i) = *(str + i);
	
	return aux;
}
int toPessoaInt (char * str, int size) { //converte char para int
	int resp = 0;
	int p_dec = 1;
	while (size > 0) {
		size--;
		resp += ((int)*(str + size) - 48) * p_dec;
		p_dec *= 10;
	}
	return resp;
}
void freePessoa (Pessoa * pessoa) {
	free(pessoa->first_name);
	free(pessoa->last_name);
	free(pessoa->email);
	pessoa->first_name = NULL;
	pessoa->last_name = NULL;
	pessoa->email = NULL;
	pessoa->age = 0;

}
//FUNCOES LISTA
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
