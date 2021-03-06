#include "Banco.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
    Contas contas1;

    InicializaContas(&contas1);
    CriarNovasContas (&contas1, 3);
    ImprimirContas (&contas1);
    ZerarSaldoConta (&contas1, 2);
    ImprimirContas (&contas1);

    return (0);
}
