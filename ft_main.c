#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
            break;
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

/*Função para buscar o nome ou parte do nome*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new_haystack;
	char	*new_needle;

	i = 0;
	new_haystack = (char *)haystack;
	new_needle = (char *)needle;
	if (new_needle[i] == '\0')
		return (new_haystack);
	while (new_haystack[i] && i < len)
	{
		j = 0;
		while (new_needle[j]
			&& new_haystack[i + j] == new_needle[j] && i + j < len)
			j++;
		if (new_needle[j] == '\0')
			return (new_haystack + i);
		i++;
	}
	return (NULL);
}

/*Busca por nome ou parte do nome*/
void    ft_find_name(void)
{
    char name[25];
    int i;
    printf("Consulta por nome\n\n");
    printf("Digite o nome ou uma parte dele: ");
    scanf("%s", name);
    struct s_student *aux = actual;
    struct s_student *next = actual;
    if (aux == NULL)
        printf("Nome não encontrado.\n\n");
    while (aux != NULL)
    {
        i = 0;
        while (aux->name == ft_strnstr(aux->name, name, sizeof(name)))
        {
            printf("Nomes encontrados: \n\n");
            printf("Nome: %s", aux->name);
            printf(" || ");
            printf("RA: %llu\n", aux->ra);
            break;
        }
        next = aux;
        aux = aux->previous;
    }
    return ;
}

/*Exclui tudo da lista*/
void    ft_free_lst(void)
{
	if (actual == NULL){
		printf("\nLista já esta vazia!");
	}else{
		actual = NULL;
        printf("A lista foi limpa!\n");
	}
}

/*Imprime o maior e menor nomes na lista*/
void    ft_print_big_small(void)
{
    char            *big;
    char            *small;
    struct s_student *aux = actual;
    struct s_student *next = actual;
    if (aux == NULL)
        printf("Esta lista esta vazia.\n\n");
    while (aux != NULL)
    {
        if (strlen(aux->name) == strlen(next->name))
        {
            big = aux->name;
            small = next->name;
        }
        else if (strlen(aux->name) >= strlen(big))
        {
          big = aux->name;
        }
        else if (strlen(aux->name) <= strlen(small))
        {
          small = aux->name;
        }
        next = aux;
        aux = aux->previous;
    }
    printf("\nMenor: %s\n", small);
    printf("Maior: %s\n", big);
    return ;
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
    "4 - Buscar por nome (Completo ou por parte) \n"
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
                printf("Saiu.\n");
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
            case 4:
                ft_find_name();
            break;
            case 5:
                ft_free_lst();
            break;
            case 6:
                ft_print_big_small();
            break;
            default:
                printf("Opção invalida.\n");
                break;
        }
    }
    return (0);
}
