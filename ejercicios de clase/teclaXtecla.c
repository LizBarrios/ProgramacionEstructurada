#include <conio.h>
#include <stdio.h>

typedef struct reg
{
    char appat[50];
    char apmat[50];
    char nom[50];
    char anio[5];
    char mes[3];
    char dia[3];
} Tdatos;

int leercadena(char str[], char msg[]);

int main()
{
    Tdatos reg;
    leercadena(reg.appat, "Apellido paterno");
    leercadena(reg.apmat, "Apellido paterno");
    leercadena(reg.nom, "Apellido paterno");
    leernum(reg.anio, "ANIO[AAAA]", 1900, 2023);
}

int leercadena(char str[], char msg[])
{
    int tecla;
    int i;
    int espacio = 1;
    i = 0;
    do
    {
        tecla = getch();
        tecla = toupper(tecla);
        if (isalpha(tecla))
        {
            printf("%c", tecla);
            str[i++] = tecla;
            espacio = 0;
        }
        else
        {
            if (tecla == 32)
            {
                if (espacio == 0)
                {
                    printf("%c", tecla);
                    str[i++] = tecla;
                    espacio = 1;
                }
            }
            else
            {
                if (tecla == 164)
                {
                    tecla = 165;
                }
                if (tecla == 165)
                {
                    printf("%c", tecla);
                    str[i++] = 165;
                }
            }
        }
    } while (tecla != 13);
    str[i] = '\0';
}
