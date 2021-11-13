#include <stdlib.h>
#include <stdio.h>

typedef struct s_alunos
{
    char *nome;
    unsigned long long *ra;
}alunos;

typedef struct s_list lista;
struct s_list {
	alunos *info;
	lista *proximo;
	lista *anterior;
};

void    initLista(lista *lst);
void    incluiFim(lista **lst, alunos *aluno);
void    incluiInicio(lista **lst, alunos *aluno);
void    printLista(lista *lst);
