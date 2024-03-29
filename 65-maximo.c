#include <stdio.h>
#include <stdlib.h>

typedef struct tItem {
    int chave;
    struct tItem *esq, *dir;
} Item;

typedef struct tArvore {
    Item *raiz;
} Arvore;

Item *criaItem(int chave) {
    Item *novoItem = (Item *)malloc(sizeof(Item));
    novoItem->chave = chave;
    novoItem->esq = novoItem->dir = NULL;
    return novoItem;
}

Arvore *criaArvoreVazia() {
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

void inserirRec(Item **raiz, int chave) {
    if (*raiz == NULL) {
        *raiz = criaItem(chave);
    } else if (chave < (*raiz)->chave) {
        inserirRec(&((*raiz)->esq), chave);
    } else if (chave > (*raiz)->chave) {
        inserirRec(&((*raiz)->dir), chave);
    }
    // Se a chave já existe, não faz nada (ignora repetições)
}

void inserir(Arvore *arvore, int chave) {
    inserirRec(&(arvore->raiz), chave);
}

void imprimirInOrdem(Item *raiz) {
    if (raiz != NULL) {
        imprimirInOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        imprimirInOrdem(raiz->dir);
    }
}

Item *maximo(Item *raiz) {
    if (raiz->dir == NULL) {
        return raiz;
    } else {
        return maximo(raiz->dir);
    }
}

void liberaItem(Item *item) {
    if (item != NULL) {
        liberaItem(item->esq);
        liberaItem(item->dir);
        printf("libera: %d\n", item->chave);
        free(item);
    }
}

void liberaArvore(Arvore *arvore) {
    liberaItem(arvore->raiz);
    free(arvore);
}

int main() {
    int n, chave;
    scanf("%d", &n);
    Arvore *arvore = criaArvoreVazia();
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &chave);
        inserir(arvore, chave);
    }
    
    imprimirInOrdem(arvore->raiz);
    printf("\n");
    
    Item *itemMax = maximo(arvore->raiz);
    printf("Maior chave: %d\n", itemMax->chave);
    
    liberaArvore(arvore);
    return 0;
}
