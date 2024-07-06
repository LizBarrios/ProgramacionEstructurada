#include <stdio.h>
#include <stdlib.h>

void readtxtfile(void);
// void create(void);
void art(void);
void datos(void);

int main()
{
    art();
    printf("\n");

    readtxtfile();
    printf("\n");
    // create();
    datos();
}

void readtxtfile(void)
{
    FILE *fa;
    char car;

    fa = fopen("cancion.txt", "r");

    if (fa)
    {
        do
        {
            car = fgetc(fa);
            printf("%c", car);

        } while (!feof(fa));

        fclose(fa);
    }
}

void art(void)
{
    FILE *fa;
    char car;

    fa = fopen("ascciArt.txt", "r");

    if (fa)
    {
        do
        {
            car = fgetc(fa);
            printf("%c", car);

        } while (!feof(fa));
        printf("\n\n");

        fclose(fa);
    }
}
/*
void create(void)
{
    FILE *fa;
    char car;
    fa = fopen("nombre.txt", "a");
    fprintf(fa, "LIZETH BARRIOS RETANA 19 NACIDA EN DURANGO \n");
    fclose(fa);
}
*/
void datos(void)
{
    FILE *fa;
    char nombre[20], apPat[20], apMat[20], ciudad[20];
    fa = fopen("datos.txt", "w");
    gets(nombre);
    gets(apPat);
    gets(apMat);
    gets(ciudad);
    fprintf(fa, "%s %s %s %s\n", nombre, apPat, apMat, ciudad);
    fclose(fa);
}