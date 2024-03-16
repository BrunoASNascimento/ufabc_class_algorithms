#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *itens;
    int tamanho;
    int quantidade;
} LES;

LES *criaLES(int tamanho)
{
    LES *les = (LES *)malloc(sizeof(LES));
    les->itens = (char *)malloc(tamanho * sizeof(char));
    les->tamanho = tamanho;
    les->quantidade = 0;
    return les;
}

void liberaLES(LES *les)
{
    free(les->itens);
    free(les);
}

int buscaLES(LES *les, char valor)
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

void insereLES(LES *les, char valor)
{
    if (les->quantidade < les->tamanho && buscaLES(les, valor) == -1)
    {
        int i = les->quantidade - 1;
        while (i >= 0 && les->itens[i] > valor)
        {
            les->itens[i + 1] = les->itens[i];
            i--;
        }
        les->itens[i + 1] = valor;
        les->quantidade++;
    }
}

void removeLES(LES *les, char valor)
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
        printf("%c ", les->itens[i]);
    }
    printf("\n");
}

int main()
{
    int N;
    char valor, operacao;
    scanf("%d", &N);
    LES *les = criaLES(N);

    while (scanf(" %c %c", &operacao, &valor) != EOF)
    {
        switch (operacao)
        {
        case 'I':
            insereLES(les, valor);
            break;
        case 'R':
            removeLES(les, valor);
            break;
        case 'B':
            if (buscaLES(les, valor) != -1)
            {
                printf("SIM\n");
            }
            else
            {
                printf("NAO\n");
            }
            break;
        case 'M':
            mostraLES(les);
            break;
        }
    }

    liberaLES(les);
    return 0;
}
