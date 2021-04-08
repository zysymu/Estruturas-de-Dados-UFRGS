#ifndef _UI_H_
#define _UI_H_

#include "lista.h"
/**
 * Le do arquivo e preenche uma lista. Retorna 1 se der certo, 0 se algo der errado.
 */
int preencher(t_lista_enc *l, char* nome_arq);

/**
 * Pede os dados do estudante para o usuario e tenta inserir na lista
 */
void trata_inserir(t_lista_enc *l);

/**
 * Pede o numero de matricula para o usuario e tenta remover o
 * estudante correspondente da lista
 */
void trata_remover(t_lista_enc *l);

/**
 * Pede o numero de matricula para o usuario, busca o estudante correspondente
 * na lista e mostra seus dados
 */
void trata_buscar(t_lista_enc *l);

/**
 * Imprime todos os elementos da lista
 */
void trata_mostrar(t_lista_enc *l);

/**
 * Mostra a media e o desvio padrao da nota 1
 */
void trata_estatisticas1(t_lista_enc *l);

/**
 * Mostra a media e o desvio padrao da nota 2
 */
void trata_estatisticas2(t_lista_enc *l);

/**
 * Pede o nome do arquivo com os dados de outra turma,
 * cria uma nova lista e compara as duas com relacao 'a nota 1
 */
void trata_comparar_nota1(t_lista_enc *l);

/**
 * Pede o nome do arquivo com os dados de outra turma,
 * cria uma nova lista e compara as duas com relacao 'a nota 2
 */
void trata_comparar_nota2(t_lista_enc *l);

#endif // _UI_H_
