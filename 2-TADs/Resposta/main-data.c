#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main()
{
    Data d1, d2;
    int dif;

    ler_data(&d1);
    ler_data(&d2);

    imprime_data(d1);
    imprime_data(d2);

    dif = diferenca_data(d1, d2);
    printf("\n%d dias\n", dif);
}
