#include <stdio.h>
#include <stdlib.h>

typedef struct tLista {
    int *itens;
    int quantidade;
    int tamanho;
} Lista;

Lista *criaListaVazia(int tamanho) {
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->itens = (int *)malloc(tamanho * sizeof(int));
    lista->quantidade = 0;
    lista->tamanho = tamanho;
    return lista;
}

void liberaLista(Lista *lista) {
    free(lista->itens);
    free(lista);
}

int cheia(Lista *lista) {
    return lista->quantidade == lista->tamanho;
}

int vazia(Lista *lista) {
    return lista->quantidade == 0;
}

void inserir(Lista *lista, int x) {
    if (cheia(lista)) return;

    for (int i = 0; i < lista->quantidade; i++) {
        if (lista->itens[i] == x) return;
    }

    lista->itens[lista->quantidade] = x;
    lista->quantidade++;
}

void remover(Lista *lista, int x) {
    int posicao = -1;
    for (int i = 0; i < lista->quantidade; i++) {
        if (lista->itens[i] == x) {
            posicao = i;
            break;
        }
    }

    if (posicao != -1) {
        for (int i = posicao; i < lista->quantidade - 1; i++) {
            lista->itens[i] = lista->itens[i + 1];
        }
        lista->quantidade--;
    }
}

int main() {
    int q, x;
    char op;
    scanf("%d", &q);
    
    Lista *lista = criaListaVazia(q); 
    
    for (int i = 0; i < q; i++) {
        scanf(" %c %d", &op, &x);
        
        if (op == 'I') {
            inserir(lista, x);
        } else if (op == 'E') {
            remover(lista, x);
        }
    }
    
    if (vazia(lista)) {
        printf("<vazia>\n");
    } else {
        for (int i = 0; i < lista->quantidade; i++) {
            printf("%d\n", lista->itens[i]);
        }
    }

    liberaLista(lista);
    return 0;
}