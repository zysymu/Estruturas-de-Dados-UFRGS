#include "ContaBancaria.h"
#include "Banco.h"
#include <stdio.h>
#include <stdlib.h>

void InicializaContas (Contas* cnt) {
    cnt->nodos = 0;
}

void CriarNovasContas (Contas* cnt, int n) {
    cnt->contas = (ContaBancaria*) malloc(n * sizeof(ContaBancaria));

    if (cnt->contas == NULL) {     
        printf("\nERRO: memoria nao alocada no malloc\n"); 
        exit(0);
    }

    for (int i=0; i<n; i++) {
        int num_conta = i;
        double saldo_conta;
        ContaBancaria conta;

        printf("saldo da conta %d: ", num_conta);
        scanf("%lf", &saldo_conta);

        Inicializa(&conta, num_conta, saldo_conta);

        cnt->contas[cnt->nodos] = conta;
        cnt->nodos++;
    }
}

void ImprimirContas (Contas* cnt) {
    for (int i=0; i<cnt->nodos; i++) {
        Imprime(cnt->contas[i]);
    }
}

void ZerarSaldoConta (Contas* cnt, int num) {
    if (VerificaNum(cnt->contas[num], num)) {
        printf("saldo antes: %f\n", ConsultaSaldo(cnt->contas[num]));
        cnt->contas[num].saldo = 0;
        printf("saldo depois: %f\n", ConsultaSaldo(cnt->contas[num]));
    }

    else printf("\nconta nao encontrada\n");

}
