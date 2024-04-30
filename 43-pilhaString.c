#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100

typedef struct
{
    char **itens;
    int topo;
    int capacidade;
} Pilha;

Pilha *criaPilha(int capacidade)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->itens = (char **)malloc(capacidade * sizeof(char *));
    for (int i = 0; i < capacidade; i++)
    {
        p->itens[i] = (char *)malloc(MAX_STR * sizeof(char));
    }
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

void liberaPilha(Pilha *p)
{
    for (int i = 0; i < p->capacidade; i++)
    {
        free(p->itens[i]);
    }
    free(p->itens);
    free(p);
}

int estaCheia(Pilha *p)
{
    return p->topo == p->capacidade - 1;
}

int estaVazia(Pilha *p)
{
    return p->topo == -1;
}

void empilhar(Pilha *p, char *valor)
{
    if (!estaCheia(p))
    {
        strcpy(p->itens[++p->topo], valor);
    }
}

void desempilhar(Pilha *p)
{
    if (!estaVazia(p))
    {
        p->topo--;
    }
}

void exibirTopo(Pilha *p)
{
    if (!estaVazia(p))
    {
        printf("%s\n", p->itens[p->topo]);
    }
}

void exibirPilhaTopoParaBase(Pilha *p)
{
    for (int i = p->topo; i >= 0; i--)
    {
        printf("%s ", p->itens[i]);
    }
    printf("\n");
}

void exibirPilhaBaseParaTopo(Pilha *p)
{
    for (int i = 0; i <= p->topo; i++)
    {
        printf("%s ", p->itens[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    char operacao, valor[MAX_STR];
    scanf("%d", &n);

    Pilha *pilha = criaPilha(n);

    while (scanf(" %c", &operacao) != EOF)
    {
        if (operacao == 'E')
        {
            scanf("%s", valor);
            empilhar(pilha, valor);
        }
        else if (operacao == 'D')
        {
            desempilhar(pilha);
        }
        else if (operacao == 'T')
        {
            exibirTopo(pilha);
        }
        else if (operacao == 'X')
        {
            exibirPilhaTopoParaBase(pilha);
        }
        else if (operacao == 'B')
        {
            exibirPilhaBaseParaTopo(pilha);
        }
    }

    liberaPilha(pilha);
    return 0;
}
