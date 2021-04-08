#include "estatisticas.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int max_nota1 (t_lista_enc *l) {
    float nota_atual;
    float nota_max = -1;
    int i = 0;
    int pos;

    if (l->ini != NULL) {
        t_nodo* atual = l->ini;
    
        while (atual != NULL) {
            nota_atual = atual->dado.nota1;

            if (nota_atual > nota_max) {
                nota_max = nota_atual;
                pos = i;
            }

            atual = atual->prox;
            i++;
        }
    }

    return pos;
}

int min_nota1 (t_lista_enc *l) {
    float nota_atual;
    float nota_min = 99;
    int i = 0;
    int pos;

    if (l->ini != NULL) {
        t_nodo* atual = l->ini;
    
        while (atual != NULL) {
            nota_atual = atual->dado.nota1;

            if (nota_atual < nota_min) {
                nota_min = nota_atual;
                pos = i;
            }

            atual = atual->prox;
            i++;
        }
    }

    return pos;
}

int max_nota2 (t_lista_enc *l) {
    float nota_atual;
    float nota_max = -1;
    int i = 0;
    int pos;

    if (l->ini != NULL) {
        t_nodo* atual = l->ini;
    
        while (atual != NULL) {
            nota_atual = atual->dado.nota2;

            if (nota_atual > nota_max) {
                nota_max = nota_atual;
                pos = i;
            }

            atual = atual->prox;
            i++;
        }
    }

    return pos;
}

int min_nota2 (t_lista_enc *l) {
    float nota_atual;
    float nota_min = 99;
    int i = 0;
    int pos;

    if (l->ini != NULL) {
        t_nodo* atual = l->ini;
    
        while (atual != NULL) {
            nota_atual = atual->dado.nota2;

            if (nota_atual < nota_min) {
                nota_min = nota_atual;
                pos = i;
            }

            atual = atual->prox;
            i++;
        }
    }

    return pos;
}

float media_nota1 (t_lista_enc *l) {
    float total_nota = 0;
    int i = 0;

    if (l->ini != NULL) {
        t_nodo* atual = l->ini;
    
        while (atual != NULL) {
            total_nota += atual->dado.nota1;
            atual = atual->prox;
            i++;
        }
    }

    return total_nota/(i+1);
}

float media_nota2 (t_lista_enc *l) {
    float total_nota = 0;
    int i = 0;

    if (l->ini != NULL) {
        t_nodo* atual = l->ini;
    
        while (atual != NULL) {
            total_nota += atual->dado.nota2;
            atual = atual->prox;
            i++;
        }
    }

    return total_nota/(i+1);
}

float soma_desv_quad(t_lista_enc* l){
    float soma_quad = 0;
    float media = media_nota1(l);
    t_nodo* atual;

    for(atual = l->ini; atual != NULL ; atual = atual->prox ){
        soma_quad += pow(atual->dado.nota1 - media, 2);
    }
    return soma_quad;
}

float soma_desv_quad2(t_lista_enc* l){
    float soma_quad = 0;
    float media = media_nota2(l);
    t_nodo* atual;

    for(atual = l->ini; atual != NULL ; atual = atual->prox ){
        soma_quad += pow(atual->dado.nota2 - media, 2);
    }
    return soma_quad;
}

float desv_pad_nota1(t_lista_enc *l){
    return sqrt(soma_desv_quad(l) / tamanho(l));
}

float desv_pad_nota2(t_lista_enc *l){
    return sqrt(soma_desv_quad2(l) / tamanho(l));
}

/* //nao estamos utilizando
float desv_pad_nota1_amostral(t_lista_enc *l){
    return sqrt(soma_desv_quad(l) / (tamanho(l) -1));
}
*/

int t_test_ind_nota1(t_lista_enc *l1, t_lista_enc *l2){
    if(tamanho(l1) != tamanho(l2)){
        return -1;
    }
    int N = tamanho(l1);

    float dif = 0, dif_quad = 0;
    t_nodo *a1, *a2;

    for(a1 = l1->ini, a2 = l2->ini; a1 != NULL; a1 = a1->prox, a2 = a2->prox){
        dif += a1->dado.nota1 - a2->dado.nota1;
        dif_quad += pow(a1->dado.nota1 - a2->dado.nota1, 2);
    }

    float t_calc = (dif / N) / sqrt( (dif_quad - (pow(dif, 2)/N) ) / ((N-1)*N) ) ;

    float t_tabela = tabela_t(0.025, N-1);

    //printf("Calc: %f, tab: %f\n", t_calc, t_tabela); //descomente para ver os valores

    if (fabs(t_calc) > t_tabela) return T_TEST_DIFERENTE;
    else return T_TEST_IGUAL;

}

int t_test_ind_nota2(t_lista_enc *l1, t_lista_enc *l2){
    if(tamanho(l1) != tamanho(l2)){
        return -1;
    }
    int N = tamanho(l1);

    float dif = 0, dif_quad = 0;
    t_nodo *a1, *a2;

    for(a1 = l1->ini, a2 = l2->ini; a1 != NULL; a1 = a1->prox, a2 = a2->prox){
        dif += a1->dado.nota2 - a2->dado.nota2;
        dif_quad += pow(a1->dado.nota2 - a2->dado.nota2, 2);
    }

    float t_calc = (dif / N) / sqrt( (dif_quad - (pow(dif, 2)/N) ) / ((N-1)*N) ) ;

    float t_tabela = tabela_t(0.025, N-1);

    //printf("Calc: %f, tab: %f\n", t_calc, t_tabela); //descomente para ver os valores

    if (fabs(t_calc) > t_tabela) return T_TEST_DIFERENTE;
    else return T_TEST_IGUAL;
}

float tabela_t(float valor_p, int grau_lib){
    // valores tipo float tem que ser comparados com uma faixa de tolerancia
    if(fabs(valor_p - 0.025) > 0.00001 ) return -1; //erro: nao temos a tabela t para p != 0.025


    /**
     * Tabela-T para valor-p igual a 0.025 de 0 a 30 graus de liberdade.
     * O valor no indice 0 corresponde a infinitos graus de liberdade.
     * Fonte: http://www.statisticshowto.com/tables/t-distribution-table/
     *
     * Os dois underscores sao uma convencao para sugerir nao se utilizar
     * o array em outro modulo alem do de estatisticas
     */
    float __tabela025[31] = {
        1.960, 12.706, 4.303, 3.182, 2.776, 2.571, 2.447,
        2.365, 2.306, 2.262, 2.228, 2.201, 2.179, 2.160,
        2.145, 2.131, 2.120, 2.110, 2.101, 2.093, 2.086,
        2.080, 2.074, 2.069, 2.064, 2.060, 2.056, 2.052,
        2.048, 2.045, 2.042
    };

    return __tabela025[grau_lib];
}

