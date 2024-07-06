/*
    Barrios Retana Lizeth 372813
    26-sep-23
    Realiza programa en C el programa debera tener el siguiente menu:
     MENU
        1.- LLENAR VECTOR 1 (MANUALMENTE)
        2.- LLENAR VECTOR 2 ALEATORIAMENTE
        3.- LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2)
        4.- IMPRIMIR VECTORES
        5.- LLENA MATRIZ 4 X 4
        6.- IMPRIMIR MATRIZ
        0.- SALIR
    NOTA: EL PROGRAMA DEBERA REPETIRSE CUANTAS VECES LO DESEE EL USUARIO
    NOTA 2: EL VECTOR 1 DE 10 POSICIONES, NUMEROS DEL 30 AL 70
    NOTA 3: EL VECTOR 2 DE 10 POSICIONES CON NUMEROS GENERADOS ALEATORIAMENTE DEL 1 AL 20 (SIN REPETIR)
    NOTA 4: EL VECTOR 3 DE 20 POSICIONES, CON LOS DATOS DEL ARREGLO1 Y ARREGLO2
    NOTA 5: MATRIZ 4 X 4 LLENARLA CON LOS DATOS DEL VECTOR1 Y VECTOR2,
    BRL_act8_1_932
*/
#include <stdio.h>
#include <string.h>
#include <time.h>
// funciones
int validarnumeros(char mensaje[], int ri, int rf);
int Num(int ri, int rf);
void llenarVectorManualmente();
void llenarVectorAleatoreamente();
/*
void llenarVector3();
void imprimirVectores();
void llenarMatriz();
void imprimirMatriz();
*/
// variables globales
int vector1[10];
int vector2[10];
int vector3[20];
int matriz[4][4];

int main()
{
    int opc, eleccion, sig, menu, x;
    do
    {
        menu = 1;
        opc = validarnumeros("QUE ACTIVIDAD DESEA REALIZR?\nMENU\n1.- LLENAR VECTOR 1 (MANUALMENTE)\n2.- LLENAR VECTOR 2 ALEATORIAMENTE\n3.- LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2)\n4.- IMPRIMIR VECTORES\n5.- LLENA MATRIZ 4 X 4\n6.- IMPRIMIR MATRIZ\n0.- SALIR\n", 0, 6);
        switch (opc)
        {
        case 0:
            printf("FIN DEL PROGRAMA");
            break;
        case 1:
            llenarVectorManualmente(vector1);
            x = validarnumeros("Deseas realizar otra opcion?\n1.si\n2.no\n", 1, 2);
            if (x == 1)
            {
                menu = 0;
            }
            else
            {
                printf("FIN DEL PROGRAMA");
            }
            break;
        case 2:
            srand(time(NULL));
            llenarVectorAleatoreamente();
            x = validarnumeros("Deseas realizar otra opcion?\n1.si\n2.no\n", 1, 2);
            if (x == 1)
            {
                menu = 0;
            }
            else
            {
                printf("FIN DEL PROGRAMA");
            }
            break;
            /*
        case 3:
            llenarVector3();
            x = validarnumeros("Deseas realizar otra opcion?\n1.si\n2.no", 1, 2);
            if (x == 1)
            {
                menu = 0;
            }
            else
            {
                printf("FIN DEL PROGRAMA");
            }
            break;
        case 4:
            imprimirVectores();
            x = validarnumeros("Deseas realizar otra opcion?\n1.si\n2.no", 1, 2);
            if (x == 1)
            {
                menu = 0;
            }
            else
            {
                printf("FIN DEL PROGRAMA");
            }
            break;
        case 5:
            llenarMatriz();
            x = validarnumeros("Deseas realizar otra opcion?\n1.si\n2.no", 1, 2);
            if (x == 1)
            {
                menu = 0;
            }
            else
            {
                printf("FIN DEL PROGRAMA");
            }
            break;
        case 6:
            imprimirMatriz();
            x = validarnumeros("Deseas realizar otra opcion?\n1.si\n2.no", 1, 2);
            if (x == 1)
            {
                menu = 0;
            }
            else
            {
                printf("FIN DEL PROGRAMA");
            }
            break;
            */
        }
    } while (menu == 0);

    return 0;
}
void llenarVectorManualmente()
{
    // NOTA 2: EL VECTOR 1 DE 10 POSICIONES, NUMEROS DEL 30 AL 70
    int i;
    for (i = 0; i < 10; i++)
    {
        vector1[i] = validarnumeros("ingrese los numeros para llenar el vector del 30 al 70: \n", 30, 70);
    }
}
void llenarVectorAleatoreamente()
{
    // NOTA 3: EL VECTOR 2 DE 10 POSICIONES CON NUMEROS GENERADOS ALEATORIAMENTE DEL 1 AL 20 (SIN REPETIR)
    int j, k;
    for (j = 0; j < 10; j++)
    {
        vector2[j] = Num(1, 20);
        for (k = 0; k < j; k++)
        {
            if (vector2[k] == vector2[j])
            {
                vector2[j] = Num(1, 20);
                k = -1;
            }
        }
        printf("%d\n",vector2[j]);
    }
}
//cortina de humo 
//aqui nada paso 
int validarnumeros(char mensaje[], int ri, int rf)
{
    char menu[100];
    int num;
    do
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(menu);
        num = atoi(menu);
        if (num < ri || num > rf)
        {
            printf("INGRESE EL NUMERO OTRA VEZ PORFAVOR\n");
        }
    } while (num < ri || num > rf);
    return num;
}
int Num(int ri, int rf)
{
    int r;
    r = (rf - ri) + 1;
    return (rand() % r) + ri;
}