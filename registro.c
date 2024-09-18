#include <stdio.h>
#include <stdlib.h>
#define MAXIMO 100

struct aln {
    char nome[100];
    int idade;
    int matricula;
};

typedef struct aln Aluno;

void incluir (Aluno a[MAXIMO], int *contador) {
    
    if (*contador >= MAXIMO) {
        printf("Quantidade maxima excedida!\n");
        return;
    }
    Aluno novoAluno;
    printf("");

    (*contador++);
}

int main ()
{
    int opcao;

    do {
        system("cls");
        printf("\n----------------------------------------------------------\n");
        printf("\tGerenciamento de cadastro de alunos\t");
        printf("\n----------------------------------------------------------\n");

        printf("1: Incluir aluno\n");
        printf("2: Consultar aluno\n");
        printf("3: Alterar dados do aluno\n");
        printf("4: Excluir aluno\n");
        printf("5: Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printf("Saindo!");
            break;
        default:
            printf("ERRO! Comando invalido");
            break;
        }
    } while (opcao != 5);
    return 0;
}