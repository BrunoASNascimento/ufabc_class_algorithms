#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tPalavra
{
    char texto[101];
    int consultas;
    struct tPalavra *ant, *prox;
} Palavra;

typedef struct
{
    Palavra *primeiro, *ultimo;
} Lista;

Lista *criaLista()
{
    Lista *novaLista = (Lista *)malloc(sizeof(Lista));
    novaLista->primeiro = novaLista->ultimo = NULL;
    return novaLista;
}

Palavra *criaPalavra(char *texto)
{
    Palavra *novaPalavra = (Palavra *)malloc(sizeof(Palavra));
    strcpy(novaPalavra->texto, texto);
    novaPalavra->consultas = 1;
    novaPalavra->ant = novaPalavra->prox = NULL;
    return novaPalavra;
}

void liberaLista(Lista *lista)
{
    Palavra *p = lista->primeiro;
    while (p != NULL)
    {
        Palavra *temp = p;
        p = p->prox;
        free(temp);
    }
    free(lista);
}

void ajustarPosicao(Lista *lista, Palavra *palavra)
{
    while (palavra->ant != NULL && palavra->consultas > palavra->ant->consultas)
    {
        // Troca com o anterior
        Palavra *ant = palavra->ant;
        if (ant->ant)
            ant->ant->prox = palavra;
        else
            lista->primeiro = palavra;
        if (palavra->prox)
            palavra->prox->ant = ant;
        else
            lista->ultimo = ant;
        ant->prox = palavra->prox;
        palavra->ant = ant->ant;
        ant->ant = palavra;
        palavra->prox = ant;
    }
}

void inserirAtualizar(Lista *lista, char *texto)
{
    Palavra *p = lista->primeiro;
    while (p != NULL && strcmp(p->texto, texto) != 0)
    {
        p = p->prox;
    }
    if (p)
    {
        p->consultas++;
        ajustarPosicao(lista, p);
    }
    else
    {
        Palavra *novaPalavra = criaPalavra(texto);
        if (lista->ultimo)
        {
            lista->ultimo->prox = novaPalavra;
            novaPalavra->ant = lista->ultimo;
            lista->ultimo = novaPalavra;
        }
        else
        {
            lista->primeiro = lista->ultimo = novaPalavra;
        }
    }
}

void imprimirLista(Lista *lista)
{
    Palavra *p = lista->primeiro;
    while (p != NULL)
    {
        printf("%s [%d]\n", p->texto, p->consultas);
        p = p->prox;
    }
    printf("\n");
}

int main()
{
    Lista *lista = criaLista();
    char palavra[101];
    while (scanf("%100s", palavra) != EOF)
    {
        inserirAtualizar(lista, palavra);
    }
    imprimirLista(lista);
    liberaLista(lista);
    return 0;
}
