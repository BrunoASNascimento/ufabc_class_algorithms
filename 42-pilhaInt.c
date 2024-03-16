#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *itens;
    int topo;
    int capacidade;
} Pilha;

Pilha *criaPilha(int capacidade)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->itens = (int *)malloc(capacidade * sizeof(int));
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

void liberaPilha(Pilha *p)
{
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

void empilhar(Pilha *p, int valor)
{
    if (!estaCheia(p))
    {
        p->itens[++p->topo] = valor;
    }
}

int desempilhar(Pilha *p)
{
    if (!estaVazia(p))
    {
        return p->itens[p->topo--];
    }
    return -1; // Indica erro
}

void exibirTopo(Pilha *p)
{
    if (!estaVazia(p))
    {
        printf("%d\n", p->itens[p->topo]);
    }
}

void exibirPilhaTopoParaBase(Pilha *p)
{
    for (int i = p->topo; i >= 0; i--)
    {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

void exibirPilhaBaseParaTopo(Pilha *p)
{
    for (int i = 0; i <= p->topo; i++)
    {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

int main()
{
    int n, valor;
    char operacao;
    scanf("%d", &n);

    Pilha *pilha = criaPilha(n);

    while (scanf(" %c", &operacao) != EOF)
    {
        switch (operacao)
        {
        case 'E':
            scanf("%d", &valor);
            empilhar(pilha, valor);
            break;
        case 'D':
            desempilhar(pilha);
            break;
        case 'T':
            exibirTopo(pilha);
            break;
        case 'X':
            exibirPilhaTopoParaBase(pilha);
            break;
        case 'B':
            exibirPilhaBaseParaTopo(pilha);
            break;
        }
    }

    liberaPilha(pilha);
    return 0;
}
