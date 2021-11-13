#include "../includes/ft_lib.h"

/*Inicia a lista*/
void    initLista(lista *lst)
{
    lst->proximo = NULL;
    lst->anterior = NULL;
    lst->info = 0;
}

/*Inclui no fim da lista*/
void    incluiFim(lista **lst, alunos *aluno)
{
    lista *novo;
    lista *aux;

    novo = (lista*)malloc(sizeof(lista*));
    novo->info = aluno;
    novo->proximo = NULL;
    novo->anterior = (*lst);

    if ((*lst)->proximo == NULL)
    {
        (*lst)->proximo=novo;
    }
    else
    {
        aux = (*lst)->proximo;
        while (aux->proximo != NULL)
            aux = aux->proximo;
        aux->proximo = novo;
        novo->anterior = aux;
    }
    
}

/*Inclui no inicio da lista*/
void    incluiInicio(lista **lst, alunos *aluno)
{
    lista *nova;
    nova = (lista*)malloc(sizeof(lista*));
    nova->info = aluno;
    nova->proximo = (*lst);
    nova->proximo = (*lst)->proximo;
    (*lst)->proximo = nova;
    if (nova->proximo != NULL)
        nova->proximo->anterior = nova;
}

/*Imprimi a lista toda*/
void    printLista(lista *lst)
{
    lista *i;
    i = lst->proximo;
    while (i != NULL)
    {
        printf("Nome: %s  RA: %s", i->info->nome, i->info->ra);
        i = i->proximo;
    }
}
