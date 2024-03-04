#include <stdio.h>

int main()
{
    int numberYear;
    int returnValue = scanf("%d", &numberYear);

    if (numberYear % 4 == 0 && numberYear % 100 != 0 || numberYear % 400 == 0){
        printf("ANO BISSEXTO\n");
    } else {
        printf("ANO NAO BISSEXTO\n");
    }

    printf("%d\n", numberYear);

    // return numberYear;
}
