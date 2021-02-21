#include <stdio.h>
#include <stdlib.h>

struct Data {
    int dia;
    int mes;
    int ano;
}; typedef struct Data Data;

void ler_data(Data *d) {
    printf("\ninsira data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &d->dia, &d->mes, &d->ano); 
    //scanf("%d/%d/%d", &d.dia, &d.mes, &d.ano); 
}

void imprime_data(Data d) {
    printf("\n%d/%d/%d", d.dia, d.mes, d.ano);
}

int diferenca_data(Data d1, Data d2) {
    float um_ano = 12; // numero de meses em um ano
    float um_mes = 30; // numero de dias em um mes

    int dif_ano, dif_mes, dif_dia; 
    int num_dias_ano, num_dias_mes, num_dias_faltantes_mes;
    int qte_dias;

    // diferencas
    dif_ano = abs(d1.ano - d2.ano);
    dif_mes = abs(d1.mes - d2.mes);
    dif_dia = abs(d1.dia - d2.dia);

    // calculo
    num_dias_ano = dif_ano * um_ano * um_mes;
    num_dias_mes = (dif_mes-1) * um_mes;
    num_dias_faltantes_mes = um_mes - dif_dia;

    qte_dias = num_dias_mes + num_dias_faltantes_mes + num_dias_ano;

    return abs(qte_dias);
}