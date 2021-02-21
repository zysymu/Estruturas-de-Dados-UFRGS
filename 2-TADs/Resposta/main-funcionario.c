#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcionario.h"
#define N 2

int main()
{
    Funcionario fs[N];
    char novo_nome[50];
    
    for (int i = 0; i < N; i++)
    {
        fs[i].cheisse = 0;
    }

    criar_funcionario(fs);
    criar_funcionario(fs);
    criar_funcionario(fs);

    imprimir_funcionarios(fs);
    salario_total(fs);

    printf("\nnome do funcionario para buscar: ");
    scanf("%s", &novo_nome);
    busca_funcionario(fs, novo_nome);

    return 0;
}
