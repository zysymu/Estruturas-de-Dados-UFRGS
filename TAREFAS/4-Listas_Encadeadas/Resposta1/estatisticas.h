#ifndef _ESTATISTICAS_H_
#define _ESTATISTICAS_H_

#include "lista.h"

#define T_TEST_DIFERENTE 1
#define T_TEST_IGUAL 0



/**
 * Retorna o indice do estudante com maior nota1
 */
int max_nota1(t_lista_enc *l);

/**
 * Retorna o indice do estudante com menor nota1
 */
int min_nota1(t_lista_enc *l);

/**
 * Retorna o indice do estudante com maior nota2
 */
int max_nota2(t_lista_enc *l);

/**
 * Retorna o indice do estudante com maior nota1
 */
int min_nota2(t_lista_enc *l);

/**
 * Retorna a media da nota 1
 */
float media_nota1(t_lista_enc *l);

/**
 * Retorna o desvio padrao populacional da nota1
 */
float desv_pad_nota1(t_lista_enc *l);

/**
 * Retorna a media da nota 2
 */
float media_nota2(t_lista_enc *l);

/**
 * Retorna o desvio padrao populacional da nota2
 */
float desv_pad_nota2(t_lista_enc *l);

/**
 * Funcao usada no calculo do desvio padrao
 */
float soma_desv_quad(t_lista_enc* l);

/**
 * Retorna o valor da distribuicao t para um valor-p e um grau de liberdade
 * especificos
 */
float tabela_t(float valor_p, int grau_lib);

/**
 * Realiza o teste-t independente para verificar
 * se a diferenca das notas1 e' significativa
 * nas duas listas
 */
int t_test_ind_nota1(t_lista_enc *l1, t_lista_enc *l2);

int t_test_ind_nota2(t_lista_enc *l1, t_lista_enc *l2);

#endif // _ESTATISTICAS_H_
