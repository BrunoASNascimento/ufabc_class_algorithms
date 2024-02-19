#include <stdio.h>
#include <stdlib.h>

struct tComplex
{
    int n;
    int d;
};

struct tComplex complexo(int, int);
struct tComplex soma(struct tComplex, struct tComplex);
struct tComplex subtrai(struct tComplex, struct tComplex);
struct tComplex multiplica(struct tComplex, struct tComplex);
struct tComplex divide(struct tComplex, struct tComplex);

struct tComplex complexo(int n, int d)
{
    struct tComplex r;
    r.n = n;
    r.d = d;
    return r;
}

struct tComplex soma(struct tComplex r1, struct tComplex r2)
{
    struct tComplex result;
    result.n = r1.n * r2.d + r2.n * r1.d;
    result.d = r1.d * r2.d;
    return result;
}

struct tComplex subtrai(struct tComplex r1, struct tComplex r2)
{
    struct tComplex result;
    result.n = r1.n * r2.d - r2.n * r1.d;
    result.d = r1.d * r2.d;
    return result;
}

struct tComplex multiplica(struct tComplex r1, struct tComplex r2)
{
    struct tComplex result;
    result.n = r1.n * r2.n;
    result.d = r1.d * r2.d;
    return result;
}

struct tComplex divide(struct tComplex r1, struct tComplex r2)
{
    struct tComplex result;
    result.n = r1.n * r2.d;
    result.d = r1.d * r2.n;
    return result;
}

int main()
{

    int n1, d1, n2, d2;
    char op;
    while (scanf("%d %d %c %d %d", &n1, &d1, &op, &n2, &d2) != EOF)
    {
        struct tComplex r1 = complexo(n1, d1);
        struct tComplex r2 = complexo(n2, d2);
        struct tComplex result;
        switch (op)
        {
        case '+':
            result = soma(r1, r2);
            break;
        case '-':
            result = subtrai(r1, r2);
            break;
        case '*':
            result = multiplica(r1, r2);
            break;
        case '/':
            result = divide(r1, r2);
            break;
        }

        printf("%d %d\n", result.n, result.d);
    }
}
