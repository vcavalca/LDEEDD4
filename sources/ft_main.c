#include "../includes/ft_lib.h"

int main(void)
{
    lista *lst;
    alunos  *aluno;
    int menu;

    lst = (lista*)malloc(sizeof(lista*));
    aluno = (alunos*)malloc(sizeof(alunos*));
    initLista(lst);

    printf(
    "\n-----------------------------------------------------\n"
    "Selecione opcao que deseja, veja nosso menu:\n"
    "-----------------\n"
    "1 - Cadastrar o aluno \n"
    "2 - Consulta por RA \n"
    "3 - Imprimir a lista \n"
    "4 - Buscar por nome \n"
    "5 - Deletar tudo\n"
    "6 - Imprimir o maior e menor nomes cadastrados \n"
    "-----------------\n"
    "0 - SAIR DO PROGRAMA.\n"
    "-----------------\n"
    );
    scanf("%d", &menu);
    switch (menu)
    {
        case 0:
            printf("Saiu.");
        break;
        case 1:
            printf("Digite o nome do aluno: ");
            scanf("%s", aluno->nome);
            printf("Digite o RA do aluno: (Somente numeros)");
            scanf("%llu", aluno->ra);
            incluiInicio(&lst, aluno);
        break;
        case 2:
        break;
        case 3:
            printLista(lst);
        break;
        default:
            printf("Opção invalida.");
            break;
    }

    free(lst);
    free(aluno);
    return (0);
}