#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//\n

typedef struct {
	char nomeDono[51];
	char nomePaciente[51];
	char racaPaciente[51];
	int idadePaciente;
	int id;
}Paciente;

void escreverArquivo(char arq[]){
	Paciente paciente;
	FILE *arquivo = fopen(arq,"ab");
	
	if(arquivo == NULL){
		printf("Erro ao abrir o arquivo\n");
	}else{
		int opWhile = 1;
		do{
			printf("---------- CADASTRO DE PACIENTES ----------\n\n");
			printf("Informe o nome do dono do paciente: ");
			gets(paciente.nomeDono);
			
			int i;
			for(i=0;i<strlen(paciente.nomeDono);i++){
				if(paciente.nomeDono[i] != NULL){
					opWhile = 0;
				}
			}
			system("cls");
			
		} while(opWhile == 1);
		
		opWhile = 1;
		do{
			printf("---------- CADASTRO DE PACIENTES ----------\n\n");
			printf("Informe o nome do paciente: ");
			gets(paciente.nomePaciente);
		
			int i;
			for(i=0; i<strlen(paciente.nomePaciente); i++){
				if(paciente.nomePaciente[i] != NULL){
					opWhile = 0;
				}
			}
			system("cls");
			
		} while(opWhile == 1);
		
		printf("Informe a raca do paciente: ");
		gets(paciente.racaPaciente);
		
		printf("Informe a idade do paciente: ");
		scanf("%d", &paciente.idadePaciente);
		
		fwrite(&paciente, sizeof(Paciente), 1, arquivo);
	}
	fclose(arquivo);
	
	printf("Paciente cadastrado com sucesso!\n");
}

void lerArquivoBi(char arq[]){
	Paciente paciente;
	FILE *arquivo = fopen(arq, "rb");
	if(arquivo == NULL){
		printf("Erro ao abrir o arquivo!\n");
	}else{
		fread(&paciente, sizeof(Paciente), 1, arquivo);
		printf("Dono: %s\n", paciente.nomeDono);
		printf("Paciente: %s\n", paciente.nomePaciente);
		printf("Raca paciente: %s\n", paciente.racaPaciente);
		printf("Idade paciente: %d\n\n", paciente.idadePaciente);
		
		fread(&paciente, sizeof(Paciente), 1, arquivo);
		printf("Dono: %s\n", paciente.nomeDono);
		printf("Paciente: %s\n", paciente.nomePaciente);
		printf("Raca paciente: %s\n", paciente.racaPaciente);
		printf("Idade paciente: %d\n", paciente.idadePaciente);
	}
}

int main(){
	char nomeArquivo[] = {"pacientes.dat"};
	
	int opWhile = 1;
	while(opWhile != 0){
		
		int opMenu;
		system("cls");
		fflush(stdin);
		
		printf("---------- CLINICA VETERINARIA DOM DOG ----------\n\n");
		printf("1 - Cadastrar paciente\n");
		printf("2 - Listar pacientes cadastrados\n");
		printf("3 - Alterar paciente\n");
		printf("4 - Excluir paciente\n");
		printf("0 - Sair\n");
		
		printf(">> ");
		scanf("%d", &opMenu);
		
		switch(opMenu)
		{
		case 1:
			system("cls");
			fflush(stdin);
			escreverArquivo(nomeArquivo);
			system("pause");
			break;
		case 2:
			lerArquivoBi(nomeArquivo);
			system("pause");
			break;
		case 3:
			system("pause");
			break;
		case 4:
			system("pause");
			break;
		case 5:
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
	
	return 0;
}//fim main