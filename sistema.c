#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Para strlen e strcspn

// ||

typedef struct {
    char nomePaciente[50];
    char racaPaciente[50];
    int idadePaciente;
    int id;
    char nomeDono[50];
} Paciente;

void cadastrarPaciente(FILE *arqPaciente, Paciente *paciente, int *qtd) {
    int ultimoId = 0;

    // Abrir o arquivo para leitura
    arqPaciente = fopen("pacientes.txt", "r");
    if (arqPaciente != NULL) {
        // Ler o arquivo para encontrar o maior ID
        while (fscanf(arqPaciente, "%d\n", &paciente->id) != EOF) {
            fgets(paciente->nomePaciente, 50, arqPaciente);
            fgets(paciente->racaPaciente, 50, arqPaciente);
            fscanf(arqPaciente, "%d\n", &paciente->idadePaciente);
            fgets(paciente->nomeDono, 50, arqPaciente);

            // Atualiza o último ID lido
            if (paciente->id > ultimoId) {
                ultimoId = paciente->id;
            }
        }
        fclose(arqPaciente);
    }
    // Definir o novo ID com base no último ID encontrado
    paciente->id = ultimoId + 1;

    int op = 1;
    do {
        printf("---------- CADASTRO DE PACIENTE ----------\n");
        printf("\nInforme o nome do dono do paciente: ");
        gets(paciente->nomeDono);
        int i;
        for (i = 0; i < strlen(paciente->nomeDono); i++) {
            if (paciente->nomeDono[i] != '\0') {
                op = 0;
            }
        }
        system("cls");
    } while (op == 1);

    op = 1;
    do {
        printf("---------- CADASTRO DE PACIENTE ----------\n");
        printf("\nInforme o nome do paciente: ");
        gets(paciente->nomePaciente);
        int i;
        for (i = 0; i < strlen(paciente->nomePaciente); i++) {
            if (paciente->nomePaciente[i] != '\0') {
                op = 0;
            }
        }
        system("cls");
    } while (op == 1);

    op = 1;
    do {
        printf("---------- CADASTRO DE PACIENTE ----------\n");
        printf("\nInforme a raca do paciente: ");
        gets(paciente->racaPaciente);
        int i;
        for (i = 0; i < strlen(paciente->racaPaciente); i++) {
            if (paciente->racaPaciente[i] != '\0') {
                op = 0;
            }
        }
        system("cls");
    } while (op == 1);

    op = 1;
    do {
        printf("---------- CADASTRO DE PACIENTE ----------\n");
        printf("\nInforme a idade do paciente: ");
        scanf("%d", &paciente->idadePaciente);
        if (paciente->idadePaciente < 0) {
            printf("\nIdade invalida!");
        }
        if (paciente->idadePaciente > 0) {
            op = 0;
        }
        system("cls");

    } while (op == 1);

    *qtd = *qtd + 1;
}


void salvarPaciente(FILE *arqPaciente, Paciente *paciente) {
    arqPaciente = fopen("pacientes.txt", "a");

    if (arqPaciente == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        exit(1);
    }

    fprintf(arqPaciente, "%d\n", paciente->id);
    fputs(paciente->nomePaciente, arqPaciente);
    fputc('\n', arqPaciente);
    fputs(paciente->racaPaciente, arqPaciente);
    fputc('\n', arqPaciente);
    fprintf(arqPaciente, "%d\n", paciente->idadePaciente);
    fputs(paciente->nomeDono, arqPaciente);
    fputc('\n', arqPaciente);

	printf("Paciente cadastrado com sucesso!\n");
    fclose(arqPaciente);
}

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

void consultarId(FILE *arqPaciente, Paciente *paciente, int *qtd){
	arqPaciente = fopen("pacientes.txt", "r");
	if(arqPaciente == NULL){
		printf("Erro ao abrir o arquivo!\n");
	}
	printf("---------- BUSCA POR ID ----------\n");
	int id;
	printf("Informe o id do paciente: ");
	scanf("%d", &id);
	if(id <= 0 || id >= *qtd+1){
		printf("Id invalido\n");
		system("pause");
	}
	int i;
	for(i=0;i<*qtd;i++){
			fscanf(arqPaciente, "%d\n", &paciente->id);
			fgets(paciente->nomePaciente, 50, arqPaciente);
			fgets(paciente->racaPaciente, 50, arqPaciente);
			fscanf(arqPaciente, "%d\n", &paciente->idadePaciente);
			fgets(paciente->nomeDono, 50, arqPaciente);
			
			if(paciente->id == id){
				printf("\n-------------------------\n\n");
				printf("Id: %d\n",paciente->id);
				printf("Nome do paciente: %s", paciente->nomePaciente);
				printf("Raca do paciente: %s", paciente->racaPaciente);
				printf("Idade do paciente: %d\n", paciente->idadePaciente);
				printf("Nome do dono: %s", paciente->nomeDono);
				printf("\n-------------------------\n\n");
				system("pause");
			}
		}
		fclose(arqPaciente);
}// fim consultar


void alterarPaciente(FILE *arqPaciente, Paciente *paciente, int *qtd) {
    if (*qtd == 0) {
        printf("Nenhum paciente cadastrado!\n");
        return;
    }

    int id, found = 0;
    printf("Informe o ID do paciente que deseja alterar: ");
    scanf("%d", &id);

    // Abrir o arquivo para leitura
    arqPaciente = fopen("pacientes.txt", "r");
    if (arqPaciente == NULL) {
        printf("\nErro ao abrir o arquivo para leitura!\n");
        return;
    }

    // Temporário para armazenar pacientes
    Paciente *pacientes = (Paciente *) malloc((*qtd) * sizeof(Paciente));
    if (pacientes == NULL) {
        printf("\nErro de alocacao de memoria!\n");
        fclose(arqPaciente);
        return;
    }

    // Carregar os pacientes do arquivo
    int i;
    for(i = 0; i < *qtd; i++) {
        fscanf(arqPaciente, "%d\n", &pacientes[i].id);
        fgets(pacientes[i].nomePaciente, 50, arqPaciente);
        fgets(pacientes[i].racaPaciente, 50, arqPaciente);
        fscanf(arqPaciente, "%d\n", &pacientes[i].idadePaciente);
        fgets(pacientes[i].nomeDono, 50, arqPaciente);

        // Remover '\n' extra das strings lidas com fgets
        pacientes[i].nomePaciente[strcspn(pacientes[i].nomePaciente, "\n")] = 0;
        pacientes[i].racaPaciente[strcspn(pacientes[i].racaPaciente, "\n")] = 0;
        pacientes[i].nomeDono[strcspn(pacientes[i].nomeDono, "\n")] = 0;

        if (pacientes[i].id == id) {
            found = 1;
            printf("\nPaciente encontrado! Insira os novos dados:\n");
            printf("Nome do dono (%s): ", pacientes[i].nomeDono);
            fflush(stdin);
            fgets(pacientes[i].nomeDono, 50, stdin);
            pacientes[i].nomeDono[strcspn(pacientes[i].nomeDono, "\n")] = 0;
            
            printf("Nome do paciente (%s): ", pacientes[i].nomePaciente);
            fflush(stdin);
            fgets(pacientes[i].nomePaciente, 50, stdin);
            pacientes[i].nomePaciente[strcspn(pacientes[i].nomePaciente, "\n")] = 0;
            
            printf("Raca do paciente (%s): ", pacientes[i].racaPaciente);
            fflush(stdin);
            fgets(pacientes[i].racaPaciente, 50, stdin);
            pacientes[i].racaPaciente[strcspn(pacientes[i].racaPaciente, "\n")] = 0;
            
            printf("Idade do paciente (%d): ", pacientes[i].idadePaciente);
            scanf("%d", &pacientes[i].idadePaciente);
        }
    }
    fclose(arqPaciente);

    if (!found) {
        printf("\nPaciente com ID %d nao encontrado!\n", id);
        free(pacientes);
        return;
    }

    // Abrir o arquivo para reescrever os dados
    arqPaciente = fopen("pacientes.txt", "w");
    if (arqPaciente == NULL) {
        printf("\nErro ao abrir o arquivo para escrita!\n");
        free(pacientes);
        return;
    }

    // Reescrever os pacientes, incluindo as alteracoes
    for (i = 0; i < *qtd; i++) {
        fprintf(arqPaciente, "%d\n", pacientes[i].id);
        fputs(pacientes[i].nomePaciente, arqPaciente);
        fputc('\n', arqPaciente);
        fputs(pacientes[i].racaPaciente, arqPaciente);
        fputc('\n', arqPaciente);
        fprintf(arqPaciente, "%d\n", pacientes[i].idadePaciente);
        fputs(pacientes[i].nomeDono, arqPaciente);
        fputc('\n', arqPaciente);
    }

    fclose(arqPaciente);
    free(pacientes);

    printf("\nPaciente alterado com sucesso!\n");
}

void excluirPaciente(FILE *arqPaciente, Paciente *paciente, int *qtd) {
    if (*qtd == 0) {
        printf("\nNenhum paciente cadastrado!\n");
        return;
    }

    int id, found = 0;
    printf("Informe o ID do paciente que deseja excluir: ");
    scanf("%d", &id);

    // Abrir o arquivo para leitura
    arqPaciente = fopen("pacientes.txt", "r");
    if (arqPaciente == NULL) {
        printf("\nErro ao abrir o arquivo para leitura!\n");
        return;
    }

    // Criar um array temporário para armazenar os pacientes
    Paciente *pacientes = (Paciente *) malloc((*qtd) * sizeof(Paciente));
    if (pacientes == NULL) {
        printf("\nErro de alocacao de memoria!\n");
        fclose(arqPaciente);
        return;
    }

    // Carregar os pacientes do arquivo
    int totalPacientes = 0;
    int i;
    for(i = 0; i < *qtd; i++) {
        fscanf(arqPaciente, "%d\n", &pacientes[i].id);
        fgets(pacientes[i].nomePaciente, 50, arqPaciente);
        fgets(pacientes[i].racaPaciente, 50, arqPaciente);
        fscanf(arqPaciente, "%d\n", &pacientes[i].idadePaciente);
        fgets(pacientes[i].nomeDono, 50, arqPaciente);

        // Remover '\n' extra das strings lidas com fgets
        pacientes[i].nomePaciente[strcspn(pacientes[i].nomePaciente, "\n")] = 0;
        pacientes[i].racaPaciente[strcspn(pacientes[i].racaPaciente, "\n")] = 0;
        pacientes[i].nomeDono[strcspn(pacientes[i].nomeDono, "\n")] = 0;

        if (pacientes[i].id == id) {
            found = 1;
            printf("\nPaciente com ID %d excluido com sucesso!\n", id);
        } else {
            totalPacientes++;
        }
    }
    fclose(arqPaciente);

    if (!found) {
        printf("\nPaciente com ID %d nao encontrado!\n", id);
        free(pacientes);
        return;
    }

    // Reescrever o arquivo sem o paciente excluido
    arqPaciente = fopen("pacientes.txt", "w");
    if (arqPaciente == NULL) {
        printf("\nErro ao abrir o arquivo para escrita!\n");
        free(pacientes);
        return;
    }

    // Reescrever os pacientes que nao foram excluidos
    for (i = 0; i < *qtd; i++) {
        if (pacientes[i].id != id) {
            fprintf(arqPaciente, "%d\n", pacientes[i].id);
            fputs(pacientes[i].nomePaciente, arqPaciente);
            fputc('\n', arqPaciente);
            fputs(pacientes[i].racaPaciente, arqPaciente);
            fputc('\n', arqPaciente);
            fprintf(arqPaciente, "%d\n", pacientes[i].idadePaciente);
            fputs(pacientes[i].nomeDono, arqPaciente);
            fputc('\n', arqPaciente);
        }
    }

    fclose(arqPaciente);
    free(pacientes);

    // Reduz a quantidade de pacientes cadastrados
    *qtd = totalPacientes;

    printf("\nPaciente removido do sistema.\n");
}

void carregarPacientes(FILE *arqPaciente, int *qtd) {
    Paciente paciente;
    *qtd = 0;  // Inicializa a quantidade de pacientes como 0

    arqPaciente = fopen("pacientes.txt", "r");
    if (arqPaciente == NULL) {
        // Se o arquivo nao existe, nao ha pacientes cadastrados
        printf("\nNenhum arquivo de pacientes encontrado. Começando um novo cadastro.\n");
        return;
    }

    // Conta o número de pacientes no arquivo
    while (fscanf(arqPaciente, "%d\n", &paciente.id) != EOF) {
        fgets(paciente.nomePaciente, 50, arqPaciente);
        fgets(paciente.racaPaciente, 50, arqPaciente);
        fscanf(arqPaciente, "%d\n", &paciente.idadePaciente);
        fgets(paciente.nomeDono, 50, arqPaciente);
        (*qtd)++;  // Incrementa a quantidade de pacientes
    }

    fclose(arqPaciente);
    printf("\n%d pacientes carregados do arquivo.\n", *qtd);
}

void main() {
    FILE *arqPaciente;
    Paciente paciente;
    int qtd = 0;  // Inicializa a quantidade de pacientes cadastrados como 0
    int opWhile = 1;

    // Carregar pacientes do arquivo no inicio do programa
    carregarPacientes(arqPaciente, &qtd);

    while (opWhile != 0) {
        int opMenu;
        system("cls");
        printf("---------- CLINICA VETERINARIA DOM DOG ----------\n\n");
        printf("1 - Cadastrar paciente\n2 - Alterar paciente\n3 - Listar paciente\n4 - Consultar por id\n5 - Excluir paciente\n0 - Sair\n\n");
        printf(">> ");
        scanf("%d", &opMenu);

        switch (opMenu) {
            case 1:
                system("cls");
                cadastrarPaciente(arqPaciente, &paciente, &qtd);
                salvarPaciente(arqPaciente, &paciente);
                system("pause");
                break;
            case 2:
                system("cls");
                alterarPaciente(arqPaciente, &paciente, &qtd);
                system("pause");
                break;
            case 3:
                system("cls");
                mostrarPacientes(arqPaciente, &paciente, &qtd);
                system("pause");
                break;
            case 4:
            	system("cls");
            	consultarId(arqPaciente, &paciente, &qtd);
            	break;
			case 5:
				system("cls");
				excluirPaciente(arqPaciente, &paciente, &qtd);
				system("pause");
				break;
            case 0:
                opWhile = 0;
                break;
            default:
                printf("Opcao invalida!\n\n");
                system("pause");
                break;
        }
    }
}