#include <stdio.h>
#include <stdlib.h>

struct tRacional racional(int, int); 
struct tRacional negativo(struct tRacional);
struct tRacional soma(struct tRacional, struct tRacional);
struct tRacional multiplica(struct tRacional, struct tRacional);
struct tRacional divide(struct tRacional, struct tRacional);
struct tRacional reduz(struct tRacional);

struct tRacional
{
    int n;
    int d;
}; 

struct tRacional racional(int n, int d) {
    struct tRacional r;
    r.n = n;
    r.d = d;
    return r;
}

struct tRacional soma(struct tRacional r1, struct tRacional r2) {
    struct tRacional result;
    result.n = r1.n * r2.d + r2.n * r1.d; 
    result.d = r1.d * r2.d; 
    return result;
}

struct tRacional multiplica(struct tRacional r1, struct tRacional r2) {
    struct tRacional result;
    result.n = r1.n *  r2.n ; 
    result.d = r1.d * r2.d; 
    return result;
}

struct tRacional divide(struct tRacional r1, struct tRacional r2) {
    struct tRacional result;
    result.n = r1.n * r2.d ; 
    result.d = r1.d * r2.n; 
    return result;
}
struct tRacional negativo(struct tRacional r) {
    struct tRacional result;
    result.n = -r.n; 
    result.d = r.d; 
    return result;
}
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

struct tRacional reduz(struct tRacional r) {
    int g = gcd(abs(r.n), abs(r.d));
    struct tRacional result;
    result.n = r.n / g;
    result.d = r.d / g;
    if (result.d < 0) {
        result.n = -result.n;
        result.d = -result.d;
    }
    return result;
}
int main()
{
    
    int n1, d1, n2, d2;
    char op;
    while (scanf("%d %d %c %d %d", &n1, &d1, &op, &n2, &d2) != EOF)
    {
        struct tRacional r1 = racional(n1, d1);
        struct tRacional r2 = racional(n2, d2);
        struct tRacional result;
        switch (op)
        {
        case '+':
            result = soma(r1, r2);
            break;
        case '-':
            result = soma(r1, negativo(r2));
            break;
        case '*':
            result = multiplica(r1, r2);
            break;
        case '/':
            result = divide(r1, r2);
            break;
        }
        result = reduz(result);
        printf("%d %d\n", result.n, result.d);
    }
}
