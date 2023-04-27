#include "Pessoa.h"

/* Rafael Toffalini de Carvalho Alves */

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
