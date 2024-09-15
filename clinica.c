#include <stdio.h>
#include <stdlib.h>

typedef struct(){
	float preco;
	char descricao[100];
	int cod;
}Servicos;

void main(){
    FILE *pont_servicos;
}//fim main

void cadastrarServico(Servicos *servico){
	char descricao[100];
	float preco;
	int cod;
	fflush(stdin);
	printf("Informe a descricao do servico: ");
	gets(descricao);
	printf("Informe o preco do servico: ");
	scanf("%f", &preco);
}
