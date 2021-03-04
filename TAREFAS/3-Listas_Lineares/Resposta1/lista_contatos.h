#ifndef LISTA_H
#define LISTA_H

#include "contato.h"

typedef struct lista_contatos {
    contato* array_contato;
    int nodos;
    int capacidade;
} lista_contatos;

/** Inicializa uma lista vazia de contatos  */
void inicializar(lista_contatos *l, int capacidade);

/** Destroi a lista de contatos, liberando o espaço ocupado */
void destruir(lista_contatos *l);

/** Mostra na tela a lista de contatos */
void print_lista(lista_contatos* l);

/** Informa quantos elementos ha na lista de contatos  */
int tamanho(lista_contatos *l);

/**
 * Adiciona um elemento na lista de contatos. Retorna 1 se
 * a insercao foi bem sucedida e 0 caso contrario
 */
int inserir(lista_contatos *l, contato novo);

/**
 * Remove um elemento em determinada posicao na lista de contatos.
 * Retorna 1 se a remocao foi bem sucedida e 0 caso contrario
 */
int remover(lista_contatos *l, int pos);

/**
 * Retorna a posicao do contato com o nome desejado, ou -1 se nao
 * encontrar
 */
int buscar(lista_contatos *l, char *nome);

/**
 * Retorna o contato na posicao indicada ou NULL se a
 * posicao for invalida
 */
contato* consultar(lista_contatos *l, int pos);

#endif // LISTA_H
