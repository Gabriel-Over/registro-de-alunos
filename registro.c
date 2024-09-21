#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#define MAXIMO 50

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
    fgets(novoAluno.nome, 100, stdin);
    
    printf("Digite a idade do aluno: ");
    scanf("%d", &novoAluno.idade);

    printf("\n=========================================\n");
    printf("Dados registrados com sucesso!");
    printf("\n\tSaindo em 3 segundos");
    printf("\n=========================================\n");
    Sleep(3 * 1000);

    a[*contador] = novoAluno;
    (*contador)++;
}

void consulta (Aluno a[MAXIMO], int *contador) {
    system("cls");
    int tecla;
    int acharAluno;
    //talvez altere o texto aqui
    if ((*contador) == 0) {
        printf("Nenhum aluno foi cadastrado!\n");
        printf("Saindo em 3 segundos...");
        Sleep(3 * 1000);
        return;
    }
    printf("Digite o numero da matricula para acessar os dados do aluno: ");
    scanf("%d", &acharAluno);

    for (int i = 0; i <= (*contador); i++) {
        if (a[i].matricula == acharAluno) {
            printf("Nome: %s", a[i].nome);
            printf("Idade: %d\n", a[i].idade);
            printf("Matricula: %d\n", a[i].matricula);

            //Unica forma que consegui achar para fazer essa parte sair sem um tempo determinado
            printf("Digite qualquer numero para para sair: ");
            scanf("%d", &tecla);
            return;
        }
    }
    //Caso nao seja encontrado nenhum aluno
    printf("Aluno nao encontrado!\n");
    Sleep(3 * 1000);
    return;
}

void alterar (Aluno a[MAXIMO], int *contador) {
    system("cls");
    if ((*contador) == 0) {
        printf("Nenhum aluno foi cadastrado!\n");
        printf("Saindo em 3 segundos...");
        Sleep(3 * 1000);
        return;
    }
    char impedirErro[1];
    int acharAluno;
    printf("Digite o numero da matricula para alterar os dados do aluno: ");
    scanf("%d", &acharAluno);

    for (int i = 0; i <= (*contador); i++) {
        if (a[i].matricula == acharAluno) {
            printf("Nome atual: %s", a[i].nome);
            printf("Alterar nome para: ");
            gets(impedirErro);
            fgets(a[i].nome, 100, stdin);

            printf("\nIdade: %d\n", a[i].idade);
            printf("Alterar idade para: ");
            scanf("%d", &a[i].idade);

            printf("\nMatricula: %d\n", a[i].matricula);
            printf("Alterar matricula para: ");
            scanf("%d", &a[i].matricula);

            printf("\n=======================================");
        }
    }
    //Caso nao seja encontrado nenhum aluno
    printf("Aluno nao encontrado!\n");
    Sleep(3 * 1000);
    return;
}

void excluir (Aluno a[MAXIMO], int *contador) {
    int acharAluno;
    printf("Digite o numero da matricula para excluir o aluno: ");
    scanf("%d", &acharAluno);

    for (int i = 0; i <= (*contador); i++) {
        if (a[i].matricula == acharAluno) {
            printf("Excluindo dados...");
            for (int j = i; j <= (*contador); j++) {
                a[j] = a[j + 1];
            }
            (*contador)--;
            Sleep(3 * 1000);
            return;
        }
    }
    //Caso nao seja encontrado nenhum aluno
    printf("Aluno nao encontrado!\n");
    Sleep(3 * 1000);
    return;
}

int main ()
{
    int opcao;
    Aluno aluno[MAXIMO];
    int contador = 0;
    do {
        system("cls");
        printf("----------------------------------------------------------\n");
        printf("\tGerenciamento de cadastro de alunos\t");
        printf("\n----------------------------------------------------------\n");

        printf("Alunos cadastrados: %d\n\n", contador);
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
            alterar(aluno, &contador);
            break;
        case 4:
            excluir(aluno, &contador);
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