#include <stdio.h>
#include <conio.h>
#define ESC 27

int main(void)
{
    int tecla;
    {
        tecla = getch();
        printf("%c = %d\n", tecla, tecla);
    }
    while (tecla != ESC)
    return 0;
}