/* 
 * ### IMPLEMENTACAO DE LISTA POR MEIO DE ARRANJO ###
 * Rafael Toffalini de Carvalho Alves
 */

//--> LIB'S
#include "ListaArranjo.h"

//--> MACROS
#define SMAXLEN 200 //tamanho maximo da String

//--> STRUCT STRING
typedef struct String { //struct com vetor de char e seu temanho para facilitar passagem de parametros
	int size;
	char * str;
}String;
//--> HEADER STRING
String * makeString (char *, int); //retorna ponteiro para string
void freeString (String *); //libera conteudo de string
String * parseSubString (String *); //copia I+posicao da String de entrada
int parseIntFromString (String *); // converte char para int

//--> HEADER
int strSize (char *); //funcao auxiliar para contar tamanho da string
String * readInput (); //funcao para entradad de dados que retorna string

// ######## DRIVER ############
	int main (int argc, char * argv[]) {
		String * obj = NULL;
		String * sub_obj = NULL;
		int position = 0;
		Lista * lista = makeLista(20); //lista eh criada com tamanho 20 (poderia ser qlqr tamanho menor q LMAXLEN)
		
		printf("\n");
		while ((obj = readInput())) { //enquanto ler entrada diferente de NULL
			if (*(obj->str + 0) == '"') { //Entrada sem Instrucao eh tratada como inserir no final da lista
				Pessoa * obj_pessoa = makePessoa(obj->str, obj->size);
				if (obj_pessoa)
					insertLista(lista, obj_pessoa);
			}else {
				if (*(obj->str + 0) == 'R' && obj->size == 1){ //entrada de R sozinho remove ultimo elemento da lista
					removeLista(lista);
				}else if (*(obj->str + 0) == 'R') { //entrada com R+posicao -> remove elemento da lista dada posicao
					position = parseIntFromString(obj);
					removeListaPos(lista, position);
				}else if (*(obj->str + 0) == 'I') { //entrada com I+posicao+Pessoa -> insere elemento dada posicao
					sub_obj = parseSubString(obj);
					Pessoa * obj_pessoa = makePessoa(obj->str+sub_obj->size, obj->size-sub_obj->size);
					position = parseIntFromString(sub_obj);
					if (obj_pessoa)
						insertListaPos(lista, obj_pessoa, position);
				}

			}

			freeString(obj);
			free(obj);
			obj = NULL;
		}
		printf("\nLista Final: \n");
		printLista(lista);
		return 0;
	}//END_MAIN

// ########## FUNCOES #############
//----------- FUNCOES HEADER ----------
String * readInput () {
	char * str_aux = (char *)malloc(SMAXLEN*sizeof(char));
	int size_aux = 0;
	if (fgets(str_aux, SMAXLEN-1, stdin)) {
		String * obj = NULL;
		size_aux = strSize(str_aux);
		str_aux = (char *)realloc(str_aux, size_aux+1*sizeof(char));
		*(str_aux + size_aux) = '\0';
		obj = makeString(str_aux, size_aux);
		return obj;
	}
	return NULL;
}
int strSize (char * str_aux) {
	int resp = 0;
	while (*(str_aux + resp) != '\n' && *(str_aux + resp) != '\0')
		resp++;
	return resp-1;
}
//---------- STRING ----------------
String * parseSubString (String * obj) {
	String * temp = NULL;
	char * temp_str = NULL;
	int temp_size = 0;

	while (*(obj->str + temp_size) != '"')
		temp_size++;

	temp_str = (char *)malloc(temp_size+1 * sizeof(char));
	*(temp_str + temp_size) = '\0';

	for (int i = 0; i < temp_size; i++) 
		*(temp_str + i) = *(obj->str + i);

	temp = makeString(temp_str, temp_size);
	return temp;
}
int parseIntFromString (String * obj) {
	int pdec = 1;
	int resp = 0;
	for (int i = obj->size-1; i > 0; i--) {
		if ((int)*(obj->str + i) != 32) {
			resp += ((int)*(obj->str + i) - 48) * pdec;
			pdec *= 10;
		}
	}
	return resp;
}
String * makeString (char * str_aux, int size_aux) {
	String * obj = (String *)malloc(1*sizeof(String));
	obj->str = str_aux;
	obj->size = size_aux;
	return obj;
}
void freeString (String * obj) {
	if (obj->str) {
		free(obj->str);
		obj->str = NULL;
		obj->size = 0;

	}
}
