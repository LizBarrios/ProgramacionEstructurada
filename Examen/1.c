#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct datos
{
    double dat;
} Tdatos;

void ArchivoTexto(Tdatos Datos, int NumDatos, FILE *fa, char *NombreDArchivo);
void cargar_muestra(FILE *nombre, int datos);
void cargar(Tdatos datos[], FILE *nombre, int n);

int main()
{
    Tdatos dato[10000];
    FILE *fa;
    int menu = 1;
    char nombre[20];
    int op;
    int numDatos;

    do
    {
        printf("Ingrese la opcion que desea hacer\n");
        printf("1. cargar\n2.imprimir\n3.midia\n4.moda\n5.mediana\n6.varianza y desviacion\n7. tercer cuartil\n8. archivo d etexto\n9. archivo binario\n10.imprimir archivo binario\0.salir\n");
        fflush(stdin);
        gets(op);
        switch (op)
        {
        case 0:
            system("cls");
            printf("FIN DEL PROGRAMA");
            menu = 1;
            return 0;
            break;
        case 1:
            printf("Ingresa el nombre del archivo (sin extension): ");
            fflush(stdin);
            gets(nombre);
            strcat(nombre, ".txt");
            cargar(datos, nombre, numDatos);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            printf("ingresa el nombre del archivo");
            fflush(stdin);
            gets(nombre);
            strcat(nombre, ".txt");
            printf("ingrese la cantidad de numeros de datos");
            fflush(stdin);
            gets(numDatos);
            ArchivoTexto(dato, numDatos, fa, nombre);
            break;
        case 9:
            break;
        case 10:
            break;
        }
    } while (!menu);
}

void cargar_muestra(FILE *nombre, int datos)
{
    FILE *fa;
    double valores;
    int i;

    fa = fopen("archivo", "w");
    if (fa == NULL)
    {
        perror("No se pudo abrir el archivo");
        return;
    }
    if (datos == 0)
    {
        fprintf(fa, "No hay registros para imprimir.\n");
        fclose(fa);
        return;
    }

    for (int i = 0; i < datos; i++)
    {
        fprintf(fa, "%d", i);
        fclose(fa);
    }
}

void ArchivoTexto(Tdatos Datos, int NumDatos, FILE *fa, char *NombreDArchivo)
{
    int i;
    fa = fopen(NombreDArchivo, "w");
    for (int i = 0; i < NumDatos; i++)
    {
        if (!feof(fa))
        {
            fprintf(fa, " ");
        }
    }
    if (NumDatos == 0)
    {
        fprintf(fa, "No hay datos para imprimir.\n");
        fclose(fa);
        return;
    }

    for (i = 0; i <= NumDatos; i++)
    {
        fprintf(fa, " %d", i);
    }
    fclose(fa);
}

void cargar(Tdatos datos[], FILE *nombre, int n)
{
    FILE *fa;

    fa = fopen(nombre, "w");

    if (fa)
    {
        for (int i = 0; i < n; i++)
        {
            datos[i].dat = fread(n, sizeof(datos), 1, fa);
        }

        fclose(fa);
    }
}