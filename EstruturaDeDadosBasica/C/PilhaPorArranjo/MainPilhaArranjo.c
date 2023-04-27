/*
 *	### IMPLEMENTACAO DE PILHA POR MEIO DE ARRANJOS
 *	Rafael Toffalini de Carvalho Alves
 */
//--> LIB'S
#include "PilhaArranjo.h"

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

//--> HEADER
int strSize (char *); //funcao auxiliar para contar tamanho da string
String * readInput (); //funcao para entradad de dados que retorna string

// ######## DRIVER ############
        int main (int argc, char * argv[]) {
                String * obj = NULL;
                String * sub_obj = NULL;
                int position = 0;
		Pilha * pilha = makePilha(20); //pilha eh criada com tamanho 20 (poderia ser qlqr tamanho menor q LMAXLEN)

		printf("\n");
		while ((obj = readInput())) { //enquanto ler entrada diferente de NULL
			
			if (*(obj->str + 0) == '"') { //Entrada sem Instrucao eh tratada como inserir na pilha
				Pessoa * obj_pessoa = makePessoa(obj->str, obj->size);
				if (obj_pessoa)
					pilhaPush(pilha, obj_pessoa);

			}else if (*(obj->str + 0) == 'R' && obj->size == 1){ //Entrada com R sozinho eh tratada como remocao da pilha
					pilhaPop(pilha);
			}

			freeString(obj);
			free(obj);
			obj = NULL;
		}
		printf("\nPilha Final: \n");
		printPilha(pilha);
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
