#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#define MAXIMO 100

//Dados dos alunos
struct aln {
    char nome[100];
    int idade;
    int matricula;
};

//Define um nome para a struct
typedef struct aln Aluno;

//Adicionar aluno
void incluir (Aluno a[MAXIMO], int *contador) {
    system("cls");
    char impedirErro[1]; //Gambiarra pra fazer a funcao funcionar

    if (*contador >= MAXIMO) {
        printf("Quantidade maxima excedida!\n");
        Sleep(3 * 1000);
        return;
    }

    Aluno novoAluno;

    /* **** Entrada de dados **** */
    printf("Digite a matricula do aluno: ");
    scanf("%d", &novoAluno.matricula);

    printf("Escreva o nome do aluno: ");
    gets(impedirErro);
    gets(novoAluno.nome);
    
    printf("Digite a idade do aluno: ");
    scanf("%d", &novoAluno.idade);

    printf("\n\n=========================================\n");
    printf("Dados registrados com sucesso!");
    printf("\n\tSaindo em 3 segundos");
    printf("\n=========================================\n");
    Sleep(3 * 1000);

    a[*contador] = novoAluno;
    (*contador++);
}

void consulta (Aluno a[MAXIMO], int *contador) {
    system("cls");
    int tecla;
    int acharAluno;
    //talvez altere o texto aqui
    printf("Digite o numero da matricula para acessar os dados do aluno: ");
    scanf("%d", &acharAluno);

    for (int i = 0; i <= (*contador); i++) {
        if (a[i].matricula == acharAluno) {
            printf("Nome: %s\n", a[i].nome);
            printf("Idade: %d\n", a[i].idade);
            printf("Matricula: %d\n", a[i].matricula);
        } else {
            printf("Aluno nao encontrado!\n");
            Sleep(3 * 1000);
            return;
        }
    }

    //Unica forma que consegui achar para fazer essa parte sair sem um tempo determinado
    printf("Digite qualquer tecla para sair.");
    scanf("%d", &tecla);
}

void alterar (Aluno a[MAXIMO], int *contador) {
    
}

int main ()
{
    int opcao;
    Aluno aluno[MAXIMO];
    int contador;
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
            incluir(aluno, &contador);
            break;
        case 2:
            consulta(aluno, &contador);
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