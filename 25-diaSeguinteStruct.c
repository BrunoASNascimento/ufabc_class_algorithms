#include <stdio.h>

typedef struct tData
{
    int dia, mes, ano;
} Data;

int isBissexto(int ano);
// int isValida(Data dt);

int isBissexto(int ano)
{
    if (ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Data isValida(Data dt)
{
    int bissexto = isBissexto(dt.ano);

    if (dt.mes == 2)
    {
        if (bissexto)
        {
            if (dt.dia < 1 || dt.dia > 29)
            {
                dt.dia = 1;
                dt.mes++;
            }
        }
        else
        {
            if (dt.dia < 1 || dt.dia > 28)
            {
                dt.dia = 1;
                dt.mes++;
            }
        }
    }
    if (dt.mes == 4 || dt.mes == 6 || dt.mes == 9 || dt.mes == 11)
    {
        if (dt.dia < 1 || dt.dia > 30)
        {
            dt.dia = 1;
            dt.mes++;
        }
    }

    if (dt.dia < 1 || dt.dia > 31)
    {
        dt.dia = 1;
        dt.mes++;
    }
    if (dt.mes < 1 || dt.mes > 12)
    {
        dt.mes = 1;
        dt.ano++;
    }
    return dt;
}

int main()
{
    Data dt;
    int bissexto;

    int returnValue = scanf("%d %d %d", &dt.dia, &dt.mes, &dt.ano);
    dt.dia++;
    dt = isValida(dt);

    printf("%d %d %d\n", dt.dia, dt.mes, dt.ano);
}