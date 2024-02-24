#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIGITS 101

typedef struct
{
    char num[MAX_DIGITS];
} tInteiro;

tInteiro inteiro(char *str)
{
    tInteiro novoInteiro;
    strncpy(novoInteiro.num, str, MAX_DIGITS);
    return novoInteiro;
}

void inverterString(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

tInteiro soma(tInteiro n1, tInteiro n2)
{
    tInteiro resultado;
    char temp[MAX_DIGITS] = {0};
    int carry = 0, sum, i;

    inverterString(n1.num);
    inverterString(n2.num);

    for (i = 0; i < MAX_DIGITS - 1; i++)
    {
        int digit1 = i < strlen(n1.num) ? n1.num[i] - '0' : 0;
        int digit2 = i < strlen(n2.num) ? n2.num[i] - '0' : 0;
        sum = digit1 + digit2 + carry;
        temp[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry)
    {
        temp[i++] = carry + '0';
    }
    temp[i] = '\0';

    inverterString(temp);
    strcpy(resultado.num, temp);

    inverterString(n1.num);
    inverterString(n2.num);

    return resultado;
}

tInteiro subtrai(tInteiro n1, tInteiro n2)
{
    tInteiro resultado;
    char temp[MAX_DIGITS] = {0};
    int borrow = 0, sub, i;

    inverterString(n1.num);
    inverterString(n2.num);

    for (i = 0; i < MAX_DIGITS - 1; i++)
    {
        int digit1 = i < strlen(n1.num) ? n1.num[i] - '0' : 0;
        int digit2 = i < strlen(n2.num) ? n2.num[i] - '0' : 0;
        sub = digit1 - digit2 - borrow;
        if (sub < 0)
        {
            sub += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        temp[i] = sub + '0';
    }

    for (i = MAX_DIGITS - 2; i > 0 && temp[i] == '0'; i--)
        ;
    temp[i + 1] = '\0';

    inverterString(temp);
    strcpy(resultado.num, temp);

    inverterString(n1.num);
    inverterString(n2.num);

    return resultado;
}

tInteiro multiplica(tInteiro n1, tInteiro n2)
{
    tInteiro resultado;
    int length1 = strlen(n1.num);
    int length2 = strlen(n2.num);
    int result[MAX_DIGITS] = {0};

    inverterString(n1.num);
    inverterString(n2.num);

    for (int i = 0; i < length1; i++)
    {
        for (int j = 0; j < length2; j++)
        {
            result[i + j] += (n1.num[i] - '0') * (n2.num[j] - '0');
            result[i + j + 1] += result[i + j] / 10;
            result[i + j] %= 10;
        }
    }

    int i = length1 + length2;
    while (i > 0 && result[i] == 0)
        i--;
    int k = 0;
    for (; i >= 0; i--, k++)
    {
        resultado.num[k] = result[i] + '0';
    }
    resultado.num[k] = '\0';

    inverterString(n1.num);
    inverterString(n2.num);

    return resultado;
}

int main()
{
    char n1_str[MAX_DIGITS], n2_str[MAX_DIGITS];
    char operador;
    tInteiro n1, n2, resultado;

    while (scanf("%s %c %s", n1_str, &operador, n2_str) != EOF)
    {
        n1 = inteiro(n1_str);
        n2 = inteiro(n2_str);

        switch (operador)
        {
        case '+':
            resultado = soma(n1, n2);
            break;
        case '-':
            resultado = subtrai(n1, n2);
            break;
        case '*':
            resultado = multiplica(n1, n2);
            break;
        default:
            printf("Operador inválido.\n");
            continue;
        }

        printf("%s\n", resultado.num);
    }

    return 0;
}
