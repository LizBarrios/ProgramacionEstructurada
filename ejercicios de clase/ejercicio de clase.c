// Progrma que genere 20 numeros aleatorios entre 10-50
#include <stdio.h>
void numAleas(int n, int ri, int rf)
{
    int num, i, par, sum, rango;

    rango = (rf - ri) + 1;

    sum = 0;
    par = 0;
    for (i = 0; i < n; i++)
    {
        num = (rand() % rango) + ri;
        printf("%d\n", num);
        if (num % 2 == 0)
        {
            par++;
        }
        sum += num;
    }
    printf("CANTIDAD DE PARES %d\n", par);
    printf("CANTIDAD DE IMPARES %d\n", n - par);
    printf("LA MEDIA ES: %d\n", sum / n);
}

int main()
{
}