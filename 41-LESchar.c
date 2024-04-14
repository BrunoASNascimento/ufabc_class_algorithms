#include <stdio.h>
#include <stdlib.h>

typedef struct tList
{
    char *items;
    int count;
    int size;
} List;

List *createEmptyList(int size)
{
    List *list = malloc(sizeof(List));
    list->items = malloc(sizeof(char) * size);
    list->size = size;
    list->count = 0;
    return list;
}

void freeList(List *list)
{
    free(list->items);
    free(list);
}

int isFull(List *list)
{
    return list->count == list->size;
}

int isEmpty(List *list)
{
    return list->count == 0;
}

int findPosition(List *list, char x)
{
    int i = 0;
    while (i < list->count && list->items[i] < x)
    {
        i++;
    }
    return i;
}

void insert(List *list, char x)
{
    if (!isFull(list))
    {
        int i = findPosition(list, x), j;
        if (i == list->count || list->items[i] != x)
        {

            for (j = list->count; j > i; j--)
            {
                list->items[j] = list->items[j - 1];
            }
            list->items[j] = x;
            list->count++;
        }
    }
}

void removeItem(List *list, char x)
{
    if (!isEmpty(list))
    {
        int i = findPosition(list, x), j;
        if (i < list->count && list->items[i] == x)
        {

            for (j = i; j < list->count; j++)
            {
                list->items[j] = list->items[j + 1];
            }
            list->count--;
        }
    }
}

void printList(List *list)
{
    if (!isEmpty(list))
    {
        int i;
        for (i = 0; i < list->count - 1; i++)
        {
            printf("%c ", list->items[i]);
        }
        printf("%c\n", list->items[list->count - 1]);
    }
}

int search(List *list, char x)
{
    int i;

    for (i = 0; i < list->count; i++)
    {
        if (list->items[i] == x)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n, i;
    char x, op;
    scanf("%d", &n);
    List *list = createEmptyList(n);

    while (scanf(" %c", &op) != EOF)
    {
        switch (op)
        {
        case 'B':
            scanf(" %c", &x);
            if (search(list, x))
            {
                printf("SIM\n");
            }
            else
            {
                printf("NAO\n");
            }
            break;
        case 'R':
            scanf(" %c", &x);
            removeItem(list, x);
            break;
        case 'I':
            scanf(" %c", &x);
            insert(list, x);
            break;
        case 'M':
            printList(list);
            break;
        }
    }
    freeList(list);
    return 0;
}
