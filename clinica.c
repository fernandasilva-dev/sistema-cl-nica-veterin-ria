#include <stdio.h>
#include <stdlib.h>

typedef struct{
	float preco;
	char descricao[100];
	int cod;
}Servicos;

void cadastrarServico(Servicos *servico);

void main(){
	Servicos servico[100];
	cadastrarServico(servico);
	printf("%s",servico[0].descricao);
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
	strcpy(servico[0].descricao, descricao);
}//cadastrarServico
