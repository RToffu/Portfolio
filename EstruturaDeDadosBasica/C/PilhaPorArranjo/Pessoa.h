#ifndef PESSOA_H
#define PESSOA_H
/* Rafael Toffalini de Carvalho Alves */

#include <stdlib.h>
#include <stdio.h>

//--> STRUCT PESSOA
enum pessoa_case { //enum para melhorar a legibilidade no switch case
        F_NAME,
        L_NAME,
        P_AGE,
        P_EMAIL 
};
typedef struct Pessoa { // registro pessoa que sera inserido na estrutura
        int age;
        char * first_name;
        char * last_name;
        char * email;
}Pessoa;
//--> HEADER PESSOA
Pessoa * makePessoa (char *, int); // devolve um ponteiro tipo pessoa
void printPessoa (Pessoa *); // stdoutput das informacoes de Pessoa
char * toPessoaChar (char *, int); //copia o valor de uma str para atributo char em Pessoa
int toPessoaInt (char *, int); // passa vetor de char para int para atribuicao de age
void freePessoa (Pessoa *); // libera os ponteiros internos de Pessoa

#endif //Pessoa.h
