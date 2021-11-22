/* Grupo formado por: 
Vinicius Moura RA 2219204443
Getulio Vilanova dos Santos RA 2219202701
Pedro Henrique RA 2219205952
Murilo Alexandre Araújo RA 2219200153

Link do repositorio no Github: https://github.com/vcavalca/LDEEDD4.git
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct s_student
{
	char				name[25];
	unsigned long long	ra;
	struct s_student	*previous;
};
struct s_student *actual = NULL;

/*Cadastra na lista*/
void    ft_register(void)
{
	printf("\n#### Cadastro ####\n\n");
	struct s_student *previous = actual;
	actual = (struct s_student*)malloc(sizeof(struct s_student));
	actual->previous = previous;
	printf("Digite o nome do aluno: ");
	scanf("%s", actual->name);
	printf("Digite o RA do aluno: ");
	scanf("%llu", &actual->ra);
	printf("\nCadastrado.\n\n");
	return ;
}

/*Consultar pelo RA*/
void    ft_find_in_lst(void)
{
	unsigned long long	ra;

	printf("\n#### Consulta por RA ####\n\n");
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
			printf(" --> ");
			printf("RA: %llu", aux->ra);
			printf("\n\n");
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
	printf("\n#### Lista #####\n\n");
	struct s_student *aux = actual;
	if (aux == NULL)
		printf("\nLista Vazia!\n");
	else
	{
		while (aux != NULL)
		{
			printf("Nome: %s", aux->name);
			printf(" --> ");
			printf("RA: %llu", aux->ra);
			aux = aux->previous;
			printf("\n---------\n");
		}
	}
	return ;
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
	char	name[25];
	int		i;

	printf("\n#### Consulta por nome ####\n\n");
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
			printf("Nome encontrado: \n\n");
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
		printf("\nA lista foi limpa!\n\n");
	}
	return ;
}

/*Imprime o maior e menor nomes na lista*/
void    ft_print_big_small(void)
{
	char				*big;
	char				*small;
	struct s_student	*aux = actual;
	struct s_student	*next = actual;
	if (aux == NULL)
		printf("\nEsta lista esta vazia.\n\n");
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
	if (next != NULL)
	{
		printf("\nMenor: %s\n", small);
		printf("Maior: %s\n\n", big);
	}
	return ;
}

void	ft_print_menu(void)
{
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
	return ;
}

int main(void)
{
	int	menu;

	ft_print_menu();
	menu = 1;
	while (menu > 0 && menu < 8)
	{
		printf("Digite a opção de menu (7 para ver o menu novamente): ");
		scanf("%d", &menu);
			switch (menu)
		{
			case 0:
				system("clear");
				printf("Saiu.\n");
			break;
			case 1:
				system("clear");
				ft_register();
			break;
			case 2:
				system("clear");
				ft_find_in_lst();
			break;
			case 3:
				system("clear");
				ft_print_lst();
			break;
			case 4:
				system("clear");
				ft_find_name();
			break;
			case 5:
				system("clear");
				ft_free_lst();
			break;
			case 6:
				system("clear");
				ft_print_big_small();
			break;
			case 7:
				system("clear");
				ft_print_menu();
			break;
			default:
				system("clear");
				printf("Opção invalida.\n\n");
				break;
		}
	}
	return (0);
}
