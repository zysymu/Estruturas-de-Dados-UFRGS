#include "ContaBancaria.h"
#include <stdio.h>

void Inicializa (ContaBancaria* conta, int numero, double saldo) {
    conta->numero = numero;
    conta->saldo = saldo;
}

void Deposito (ContaBancaria* conta, double valor) {
    conta->saldo += valor;
}

void Saque (ContaBancaria* conta, double valor) {
    conta->saldo -= valor;
}

void Imprime (ContaBancaria conta) {
    printf("Numero: %d\n", conta.numero);
    printf("Saldo: %f\n", conta.saldo);
}

int VerificaNum (ContaBancaria conta, int num) {
    if (conta.numero == num) return 1;
    else return 0;
}

double ConsultaSaldo (ContaBancaria conta) {
    return conta.saldo;
}
