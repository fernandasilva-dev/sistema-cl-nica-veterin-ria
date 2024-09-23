#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// \n  ||

typedef struct{
	char nomePaciente[50];
	char racaPaciente[50];
	int idadePaciente;
	int id;
	char nomeDono[50];
	
}Paciente;

void cadastrarPaciente(FILE *arqPaciente, Paciente *paciente, int *qtd){
	
	if(*qtd == 0){
		paciente->id = 1;
	}else{
		paciente->id = *qtd + 1;
	}
	
	int op = 1;
	do
	{
		printf("---------- CADASTRO DE PACIENTE ----------\n\n");
		printf("Informe o nome do dono do paciente: ");
		gets(paciente->nomeDono);
		int i;
		for(i=0;i<strlen(paciente->nomeDono);i++){
			if(paciente->nomeDono[i] != NULL){
				op = 0;
			}
		}
		system("cls");
	} while(op == 1);
	
	op = 1;
	do
	{
		printf("---------- CADASTRO DE PACIENTE ----------\n\n");
		printf("Informe o nome do paciente: ");
		gets(paciente->nomePaciente);
		int i;
		for(i=0;i<strlen(paciente->nomePaciente);i++){
			if(paciente->nomePaciente[i] != NULL){
				op = 0;
			}
		}
		system("cls");
	} while(op == 1);
	
	op = 1;
	do
	{
		printf("---------- CADASTRO DE PACIENTE ----------\n\n");
		printf("Informe a raca do paciente: ");
		gets(paciente->racaPaciente);
		int i;
		for(i=0;i<strlen(paciente->racaPaciente);i++){
			if(paciente->racaPaciente[i] != NULL){
				op = 0;
			}
		}
		system("cls");
	} while(op == 1);
	
	op = 1;
	do
	{
		printf("---------- CADASTRO DE PACIENTE ----------\n\n");
		printf("Informe a idade do paciente: ");
		scanf("%d", &paciente->idadePaciente);
		if(paciente->idadePaciente < 0){
			printf("Idade invalida!");
		}
		if(paciente->idadePaciente > 0){
			op = 0;
		}
		system("cls");
		
	} while(op == 1);
	
	*qtd = *qtd + 1;
	
}//fim cadastrar paciente

/*void salvarPaciente(FILE *arqPaciente, Paciente *paciente){
	
}*/

void mostrarPacientes(FILE *arqPaciente, Paciente *paciente, int *qtd){
	arqPaciente = fopen("pacientes.txt", "r");
	if(arqPaciente == NULL){
		printf("Erro ao abrir o arquivo!\n");
	}

	if(*qtd == 0){
		printf("Nenhum paciente cadastrado!\n");
	}else{
		printf("------------- LISTAgem DE PACIENTES CADASTRADOS ----------------\n\n");
		int i;
		for(i=0;i<*qtd;i++){
			fscanf(arqPaciente, "%d\n", &paciente->id);
			fgets(paciente->nomePaciente, 50, arqPaciente);
			fgets(paciente->racaPaciente, 50, arqPaciente);
			fscanf(arqPaciente, "%d\n", &paciente->idadePaciente);
			fgets(paciente->nomeDono, 50, arqPaciente);
			
			printf("\n-------------------------\n\n");
			printf("Id: %d\n",paciente->id);
			printf("Nome do paciente: %s", paciente->nomePaciente);
			printf("Raca do paciente: %s", paciente->racaPaciente);
			printf("Idade do paciente: %d\n", paciente->idadePaciente);
			printf("Nome do dono: %s", paciente->nomeDono);
		}
		printf("\n-------------------------\n");
	}
	
	fclose(arqPaciente);
}

void salvarPaciente(FILE *arqPacientes, Paciente *paciente){
	
	arqPacientes = fopen("pacientesSistema.txt", "w");
	if(arqPacientes == NULL){
		printf("Erro ao abrir o arquivo!\n");
	}else{
		fwrite(&paciente, sizeof(Paciente), 1, arqPacientes);
	}
	
	fclose(arqPacientes);
}

void main(){
	
	FILE *arqPaciente;
	Paciente paciente;
	int qtd = 0;
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
			cadastrarPaciente(arqPaciente, &paciente, &qtd);
			salvarPaciente(arqPaciente, &paciente);
			system("pause");
			break;
		case 3:
			system("cls");
			fflush(stdin);
			mostrarPacientes(arqPaciente, &paciente, &qtd);
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

