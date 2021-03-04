#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"
#define N 2

struct Funcionario {
    char nome[100];
    Data data_entrada;
    float salario;
    char cargo[50];
    int cheisse;
}; typedef struct Funcionario Funcionario;


void alterar_cargo (Funcionario *f, char novo_cargo[50]) {
    strcpy(f->cargo, novo_cargo);
}

void alterar_salario (Funcionario *f, float novo_salario) {
    f->salario = novo_salario;
}

void imprimir_funcionario (Funcionario f) {
    printf("\nnome: %s; salario: %f; cargo: %s; data de entrada: ", f.nome, f.salario, f.cargo);
    imprime_data(f.data_entrada);
}

/////////////////////////////////////////////////////////////////////

void criar_funcionario (Funcionario fs[N]) {
    Funcionario f, *f_ptr;
    char cargo[50];
    float salario;
    int check;

    f_ptr = &f;

    // entrada de valores
    printf("\nnome do funcionario: "); scanf("%s", f_ptr->nome);
    printf("\nsalario do funcionario: "); scanf("%f", &salario); alterar_salario(f_ptr, salario);
    printf("\ncargo do funcionario: "); scanf("%s", &cargo); alterar_cargo(f_ptr, cargo);
    printf("\ndata de entrada do funcionario: "); ler_data(&f_ptr->data_entrada);

    //imprimir_funcionario(f);

    // checa se array esta cheio e adiciona funcionario caso tiver espaco
    check = 0;
    for (int i = 0; i < N; i++)
    {
        if (fs[i].cheisse == 0) { // caso o espaco estiver vazio
            fs[i] = f;
            fs[i].cheisse = 1;
            printf("\nfuncionario salvo!");
            break;
        } 
        else check += 1;
    }

    if (check == N) printf("\nnao ha mais espaco no vetor de funcionarios!!!");
}

void imprimir_funcionarios (Funcionario fs[N]) {
    for (int i = 0; i < N; i++)
    {
        imprimir_funcionario(fs[i]);
    }
    
}

void salario_total (Funcionario fs[N]) {
    float total = 0;
    
    for (int i = 0; i < N; i++)
    {
        total += fs[i].salario;
    }

    printf("\nsalario total: %f", total);
}

void busca_funcionario (Funcionario fs[N], char nome_busca[100]) {
    int check = 0;
    
    for (int i = 0; i < N; i++) // busca linear
    {
        if (strcmp(fs[i].nome, nome_busca)==0) {
            imprimir_funcionario(fs[i]);
            check = 1;
            break;
        } 
        
    }
    
    if (check == 0) printf("funcionario nao existe");
}
