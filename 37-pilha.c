#include <stdio.h>
#include <stdlib.h>

typedef struct tPilha
{
    int *itens;
    int topo;
    int tamanho;
} Pilha;

Pilha *criaPilhaVazia(int tamanho)
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->itens = (int *)malloc(tamanho * sizeof(int));
    pilha->topo = -1;
    pilha->tamanho = tamanho;
    return pilha;
}

void liberaPilha(Pilha *pilha)
{
    free(pilha->itens);
    free(pilha);
}

int cheia(Pilha *pilha)
{
    return pilha->topo == pilha->tamanho - 1;
}

int vazia(Pilha *pilha)
{
    return pilha->topo == -1;
}

void empilha(Pilha *pilha, int x)
{
    if (!cheia(pilha))
    {
        pilha->topo++;
        pilha->itens[pilha->topo] = x;
    }
}

int desempilha(Pilha *pilha)
{
    if (!vazia(pilha))
    {
        int valor = pilha->itens[pilha->topo];
        pilha->topo--;
        return valor;
    }
    return -1;
}

void imprimePilhaTopo(Pilha *pilha)
{
    for (int i = pilha->topo; i >= 0; i--)
    {
        printf("%d\n", pilha->itens[i]);
    }
    printf("\n");
}

void imprimePilhaBase(Pilha *pilha)
{
    for (int i = 0; i <= pilha->topo; i++)
    {
        printf("%d\n", pilha->itens[i]);
    }
    printf("\n");
}

int main()
{
    int n, valor;
    char op;
    scanf("%d", &n);

    Pilha *pilha = criaPilhaVazia(n);

    while (scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
        case 'E':
            scanf("%d", &valor);
            empilha(pilha, valor);
            break;
        case 'D':
            desempilha(pilha);
            break;
        case 'T':
            imprimePilhaTopo(pilha);
            break;
        case 'B':
            imprimePilhaBase(pilha);
            break;
        }
    }

    liberaPilha(pilha);
    return 0;
}
