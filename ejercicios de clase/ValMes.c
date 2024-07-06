#include <stdio.h>
#include "RRD.h"

int main ()
{

}

void validarMes(char mes[])
{
    int dia[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    valinum(1,dia[atoi(mes)]);
}

void leerEdo(char str[])
{
    char edos[34][3]={"liz","AG"};
    char op[3];
    atoi(leernum(op,"Edo",2));
    strcpy(str,edos[atoi(op)]);
}

