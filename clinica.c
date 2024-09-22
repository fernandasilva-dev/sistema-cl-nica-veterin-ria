#include <stdio.h>
#include <stdlib.h>
// \n

int qtd = 0;

typedef struct{
	char nomePaciente[50];
	char racaPaciente[50];
	int idadePaciente;
	int id;
	char nomeDono[50];
	
}Paciente;

void cadastrarPaciente(FILE *arqPaciente, Paciente *paciente){
	printf("---------- CADASTRO DE PACIENTE ----------\n\n");
	
	if(qtd == 0){
		paciente->id = 1;
	}
	
	paciente->id = qtd + 1;
	
	printf("Informe o nome do dono do paciente: ");
	gets(paciente->nomeDono);
	
	printf("Informe o nome do paciente: ");
	gets(paciente->nomePaciente);
	
	printf("Informe a raca do paciente: ");
	gets(paciente->racaPaciente);
	
	printf("Informe a idade do paciente: ");
	scanf("%d", &paciente->idadePaciente);
	
	qtd++;
	
}//fim cadastrar paciente

void salvarPaciente(FILE *arqPaciente, Paciente *paciente){
	
	arqPaciente = fopen("pacientes.txt", "a");
	
	if(arqPaciente == NULL){
		printf("Erro ao abrir o arquivo!");
		system("pause");
		exit(1);
	}
	fprintf(arqPaciente, "%d",paciente->id);
	fputc('\n', arqPaciente);
	
	
	fputs(paciente->nomePaciente, arqPaciente);
	fputc('\n', arqPaciente);
	
	fputs(paciente->racaPaciente, arqPaciente);
	fputc('\n', arqPaciente);
	
	fprintf(arqPaciente, "%d",paciente->idadePaciente);
	fputc('\n', arqPaciente);
	
	fputs(paciente->nomeDono, arqPaciente);
	fputc('\n', arqPaciente);
	fputc('\n', arqPaciente);
	
	fclose(arqPaciente);
}

void main(){
	
	FILE *arqPaciente;
	Paciente paciente;
	int opWhile = 1;
	
	while(opWhile != 0){
		int opMenu;
		system("cls");
		fflush(stdin);
		printf("---------- CLINICA VETERINARIA DOM DOG ----------\n\n");
		printf("1 - Cadastrar paciente\n2 - Alterar paciente\n3 - Listar paciente\n4 - Excluir paciente\n0 - Sair\n");
		printf(">> ");
		scanf("%d", &opMenu);
		
		switch(opMenu)
		{
		case 1:
			system("cls");
			fflush(stdin);
			cadastrarPaciente(arqPaciente, &paciente);
			salvarPaciente(arqPaciente, &paciente);
			system("pause");
			break;
		case 0:
			opWhile = 0;
			break;
		default:
			printf("Opcao invalida!\n\n");
			break;
		}
	}//fim while
	
	
}//fim main

