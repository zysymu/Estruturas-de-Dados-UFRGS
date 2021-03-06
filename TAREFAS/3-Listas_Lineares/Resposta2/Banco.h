#ifndef BANCO_H
#define BANCO_H
#include "ContaBancaria.h"

typedef struct Contas {
    ContaBancaria* contas;
    int nodos;
} Contas;

/* Define o número de contas existentes como sendo 0.*/ 
void InicializaContas (Contas* cnt);

/* Cria n novas contas no conjunto de contas  – solicitando ao usuário o saldo e definindo automaticamente o número da conta. */
void CriarNovasContas (Contas* cnt, int n);

/* Imprime todas as contas existentes. */ 
void ImprimirContas (Contas* cnt);

/* Dado o número num de uma conta, zera seu saldo. */ 
void ZerarSaldoConta (Contas* cnt, int num);

#endif
