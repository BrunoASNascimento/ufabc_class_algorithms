
#include <stdio.h>
void main()
{
    int num;
    scanf("%d", &num);
    if (num % 2 == 0)
    {
        printf("%d is divide by 2", num);
    }
    else
    {
        printf("%d is not divide by 2", num);
    }
}