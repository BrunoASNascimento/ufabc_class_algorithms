#include <stdio.h>
#include <stdlib.h>

#define MAX 30000

typedef struct
{
    char itens[MAX];
    int qtd;
} Lista;

void criaLista(Lista *lista)
{
    lista->qtd = 0;
}

int busca(Lista *lista, char valor)
{
    for (int i = 0; i < lista->qtd; i++)
    {
        if (lista->itens[i] == valor)
        {
            return i; // Retorna a posição se encontrar o valor
        }
    }
    return -1; // Retorna -1 se não encontrar
}

void insere(Lista *lista, char valor)
{
    if (lista->qtd >= MAX || busca(lista, valor) != -1)
    {
        return; // Ignora se a lista estiver cheia ou o valor já existir
    }

    // Inserção ordenada
    int pos;
    for (pos = lista->qtd; pos > 0 && lista->itens[pos - 1] > valor; pos--)
    {
        lista->itens[pos] = lista->itens[pos - 1];
    }
    lista->itens[pos] = valor;
    lista->qtd++;
}

void removeValor(Lista *lista, char valor)
{
    int pos = busca(lista, valor);
    if (pos == -1)
    {
        return; // Ignora se não encontrar o valor
    }

    for (int i = pos; i < lista->qtd - 1; i++)
    {
        lista->itens[i] = lista->itens[i + 1];
    }
    lista->qtd--;
}

void imprimeLista(Lista *lista)
{
    for (int i = 0; i < lista->qtd; i++)
    {
        printf("%c ", lista->itens[i]);
    }
    printf("\n");
}

int main()
{
    char operacao, valor;
    Lista lista;
    criaLista(&lista);

    while (scanf(" %c %c", &operacao, &valor) != EOF)
    {
        switch (operacao)
        {
        case 'I':
            insere(&lista, valor);
            break;
        case 'R':
            removeValor(&lista, valor);
            break;
        case 'B':
            printf("%s\n", busca(&lista, valor) != -1 ? "SIM" : "NAO");
            break;
        case 'M':
            imprimeLista(&lista);
            break;
        }
    }

    return 0;
}
