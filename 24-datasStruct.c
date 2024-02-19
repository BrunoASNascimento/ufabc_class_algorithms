#include <stdio.h>

typedef struct tData
{
    int dia, mes, ano;
} Data;

int isBissexto(int ano);
int isValida(Data dt);

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

int isValida(Data dt)
{
    int bissexto = isBissexto(dt.ano);
    
    if(dt.mes == 2){
        if(bissexto){
            if(dt.dia < 1 || dt.dia > 29){
                return 0;
            }
        } else {
            if(dt.dia < 1 || dt.dia > 28){
                return 0;
            }
        }
    }
    if (dt.mes == 4 || dt.mes == 6 || dt.mes == 9 || dt.mes == 11)
    {
        if (dt.dia < 1 || dt.dia > 30)
        {
            return 0;
        }
    }
    
    if (dt.dia < 1 || dt.dia > 31)
    {
        return 0;
    }
    if (dt.mes < 1 || dt.mes > 12)
    {
        return 0;
    }

    if (dt.ano < 0)
    {
        return 0;
    }
    return 1;
}

int main()
{
    Data dt;
    int bissexto;

    int numberValue;
    int returnValue = scanf("%d", &numberValue);

    for (int i = 0; i < numberValue; i++)
    {
        int returnValue = scanf("%d %d %d", &dt.dia, &dt.mes, &dt.ano);
        if (isValida(dt))
        {
            printf("DATA VALIDA\n");
        }
        else
        {
            printf("DATA INVALIDA\n");
        }
    }

    return 0;
}