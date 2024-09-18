#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int opcao;
    do {
        system("cls");
        printf("\n----------------------------------------------------------\n");
        printf("\tGerenciamento de cadastro de alunos\t");
        printf("\n----------------------------------------------------------\n");

        printf("Digite sua opcao: \n");
        printf("1: Cadastrar aluno\n");
        printf("2: Consultar aluno\n");
        printf("3: Alterar dados do aluno\n");
        printf("4: Excluir aluno\n");
        printf("5: Sair\n");
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