#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> 

struct Paciente {
    char nome[50];
    int idade;
    char especie[30];
    char dono[50];
};

void cadastrarPaciente(struct Paciente *paciente) {
    printf("================= CADASTRO =================\n\n");
    printf("Nome do paciente: ");
    fgets(paciente->nome, 50, stdin);
    paciente->nome[strcspn(paciente->nome, "\n")] = 0; //Remove nova linha

    printf("Idade do paciente: ");
    scanf("%d", &paciente->idade);
    getchar();

    printf("Espécie do paciente: ");
    fgets(paciente->especie, 30, stdin);
    paciente->especie[strcspn(paciente->especie, "\n")] = 0; // Remove nova linha

    printf("Nome do dono: ");
    fgets(paciente->dono, 50, stdin);
    paciente->dono[strcspn(paciente->dono, "\n")] = 0; // Remove nova linha

    printf("\n\nPaciente cadastrado com sucesso!!!\n\n");
}

void salvarPaciente(struct Paciente *paciente, FILE *arquivo) {
    fprintf(arquivo, "----------------------------------\n");
    fprintf(arquivo, "Nome: %s\n", paciente->nome);
    fprintf(arquivo, "Idade: %d\n", paciente->idade);
    fprintf(arquivo, "Espécie: %s\n", paciente->especie);
    fprintf(arquivo, "Dono: %s\n", paciente->dono);
}

void mostrarPacientes(FILE *arquivo) {
    char linha[100];
    rewind(arquivo); // rewind volta para o início do arquivo
    
    printf("=================PACIENTES=================\n\n");

    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha); // Imprime linha por linha
    }
    printf("\n\n");
    system("pause");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct Paciente paciente;
    FILE *arquivo;
    int op;

    // Abrir o arquivo para leitura e gravacao
    arquivo = fopen("pacientes.txt", "a+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    do {
        system("cls");
        printf("================= CLINICA VETERINARIA =================\n\n");
        printf("1 - Cadastrar paciente\n");
        printf("2 - Visualizar pacientes\n");
        printf("0 - Sair\n\n");
        printf(">> ");
        scanf("%d", &op);
        getchar();
        system("cls");

        switch (op) {
            case 1:
                cadastrarPaciente(&paciente);
                salvarPaciente(&paciente, arquivo);
                break;
            case 2:
                mostrarPacientes(arquivo);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (op != 0);

    fclose(arquivo); // Fecha o arquivo
    return 0;
}