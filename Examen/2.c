#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ValiNum(char mensaje[], int rs, int ri);
void cargar_muestra(char nombre[], float *vec, int *tamano);
int main()
{
    float vec[1000];
    char cargar[30];
    int opc, menu = 0, x = 0, i, tamano = 0, suma = 0;
    int media_ari = 0, mediana = 0;
    do
    {
        opc = ValiNum("MENÚ\n1. Cargar muestra\n2. Imprimir muestra\n3. Media aritmética\n4. Moda\n5. Mediana\n6. Varianza y desviación estándar\n7. Tercer cuartil\n8. Generar archivo Texto (toda la información)\n9. Generar archivo Binario (registro de cálculos)\n10. Imprimir archivo Binario\n0. Salir\n", 0, 10);

        menu = 1;
        switch (opc)
        {
        case 0:
            printf("FIN DEL PROGRAMA");
            return 0;
            break;
        case 1:
            printf("ingrese nombre del archivo\n");
            fflush(stdin);
            gets(cargar);
            strcat(cargar, ".txt");
            cargar_muestra(cargar, vec, &tamano);

            break;
        case 2:
            x = sizeof(vec) / sizeof(vec[0]);
            for (i = 0; i < tamano; i++)
            {
                printf("%f\n", vec[i]);
            }
            printf("tamano = %d\n", tamano);

            break;
        case 3:
            for (i = 0; i < tamano; i++)
            {
                suma = suma + vec[i];
            }
            media_ari = suma / tamano;
            printf("meida aritmetica= %d\n", media_ari);
            break;
        case 4:

            break;
        case 5:
            if (tamano / 2 ==1)
            {
                mediana = (vec[tamano / 2] + vec[(tamano / 2) + 1]) / 2;
            }

            break;
        }

    } while (menu == 1);
}

int ValiNum(char mensaje[], int rs, int ri)
{
    char numero[100];
    int i, repe = 0, x = 0, num = 0;
    printf("%s", mensaje);
    do
    {

        repe = 0;
        fflush(stdin);
        gets(numero);
        x = strlen(numero);
        for (i = 0; i < x; i++)
        {
            if (numero[i] >= 0 && numero[i] <= 9)
            {
                repe = 0;
            }
            else
            {
                repe = 1;
                i = x;
            }
        }

        num = atoi(numero);

    } while ((num > ri || num < rs) && repe == 1);
    return num;
}
void cargar_muestra(char nombre[], float *vec, int *tamano)
{
    FILE *fa;
    int i = 0;
    fa = fopen(nombre, "r");
    while (fscanf(fa, "%f", &vec[i]) == 1)
    {
        i++;
    }
    *tamano = i;

    fclose(fa);
}