#include <stdlib.h>
#include <stdio.h>

struct s_student
{
	char name[25];
	unsigned long long ra;
	struct s_student *previous;
};
struct s_student *actual = NULL;

/*Cadastra na lista*/
void    ft_register(void)
{
    printf("#### Cadastro ####\n\n");
    struct s_student *previous = actual;
    actual = (struct s_student*)malloc(sizeof(struct s_student));
    actual->previous = previous;
    printf("Digite o nome do aluno: ");
    scanf("%s", actual->name);
    printf("Digite o RA do aluno: ");
    scanf("%llu", &actual->ra);
    printf("Cadastrado.\n");
}

/*Consultar pelo RA*/
void    ft_find_in_lst(void)
{
    unsigned long long ra;
    printf("Consulta\n\n");
    printf("Digite o RA: ");
    scanf("%llu", &ra);
    struct s_student *aux = actual;
    struct s_student *next = actual;
    if (aux == NULL)
        printf("Nenhum aluno encontrado com esse RA.\n");
    while (aux != NULL)
    {
        if (aux->ra == ra)
        {
            printf("\nDados do aluno: \n");
            printf("Nome: %s", aux->name);
            printf(" || ");
            printf("RA: %llu", aux->ra);
        }
        next = aux;
        aux = aux->previous;  
    }    
    return ;
}

/*Print de toda a lista*/
void    ft_print_lst(void)
{
    printf("#### Lista #####\n\n");
    struct s_student *aux = actual;
    if (aux == NULL)
        printf("Lista Vazia!\n");
    else
    {
        while (aux != NULL)
        {
            printf("Nome: %s", aux->name);
            printf(" || ");
            printf("RA: %llu", aux->ra);
            aux = aux->previous;
            printf("\n---------\n");
        }
    }
}

int main(void)
{
    int menu;

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
    menu = 1;
    while (menu > 0 && menu < 7)
    {
        scanf("%d", &menu);
         switch (menu)
        {
            case 0:
                printf("Saiu.");
            break;
            case 1:
                ft_register();
            break;
            case 2:
                ft_find_in_lst();
            break;
            case 3:
                ft_print_lst();
            break;
            default:
                printf("Opção invalida.");
                break;
        }
    }
    return (0);
}
