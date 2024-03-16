#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *itens;
    int tamanho;
    int quantidade;
} LES;

LES *criaLES(int tamanho)
{
    LES *les = (LES *)malloc(sizeof(LES));
    les->itens = (int *)malloc(tamanho * sizeof(int));
    les->tamanho = tamanho;
    les->quantidade = 0;
    return les;
}

void liberaLES(LES *les)
{
    free(les->itens);
    free(les);
}

int buscaLES(LES *les, int valor)
{
    for (int i = 0; i < les->quantidade; i++)
    {
        if (les->itens[i] == valor)
        {
            return i;
        }
    }
    return -1;
}

void insereLES(LES *les, int valor)
{
    if (les->quantidade < les->tamanho && buscaLES(les, valor) == -1)
    {
        les->itens[les->quantidade++] = valor;
    }
}

void removeLES(LES *les, int valor)
{
    int posicao = buscaLES(les, valor);
    if (posicao != -1)
    {
        for (int i = posicao; i < les->quantidade - 1; i++)
        {
            les->itens[i] = les->itens[i + 1];
        }
        les->quantidade--;
    }
}

void mostraLES(LES *les)
{
    for (int i = 0; i < les->quantidade; i++)
    {
        printf("%d ", les->itens[i]);
    }
    printf("\n");
}

int main()
{
    int N, valor;
    char operacao;
    scanf("%d", &N);
    LES *les = criaLES(N);

    while (scanf(" %c", &operacao) != EOF)
    {
        switch (operacao)
        {
        case 'I':
            scanf("%d", &valor);
            insereLES(les, valor);
            break;
        case 'R':
            scanf("%d", &valor);
            removeLES(les, valor);
            break;
        case 'B':
            scanf("%d", &valor);
            printf("%s\n", buscaLES(les, valor) != -1 ? "SIM" : "NAO");
            break;
        case 'M':
            mostraLES(les);
            break;
        }
    }

    liberaLES(les);
    return 0;
}
