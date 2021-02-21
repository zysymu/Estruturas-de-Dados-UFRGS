#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_contatos.h"

/** Inicializa uma lista vazia de contatos  */
void inicializar (lista_contatos *l, int capacidade) {      
    // salvar o valor maximo do array
    l->capacidade = capacidade; 
  
    // usar malloc para criar array de tamanho `capacidade`
    l->array_contato = (contato*) malloc(l->capacidade * sizeof(contato));
    
    if (l->array_contato == NULL) { 
        printf("\ERRO: memoria nao alocada no malloc\n"); 
        exit(0); 
    } 
  
    // inicializamos a lista colocando zero nodos nela.
    // quando queremos adicionar um elemento, iremos criar um nodo e colocar o elemento
    l->nodos = 0;
}

/** Destroi a lista de contatos, liberando o espaço ocupado */
void destruir (lista_contatos *l) {
    l->nodos = 0; // zera o indice de nodos
    l->capacidade = 0; // zera a capacidade
    free(l->array_contato); // libera espaco na memoria do array
    printf("lista destruida! o espaco foi dealocado da memoria\n");
}

/** Mostra na tela a lista de contatos */
void print_lista (lista_contatos* l){
    printf("atualmente ha %d nodos na lista\n", tamanho(l));

    for (int i=0; i < l->nodos; i++) {
        printf("nodo %d | nome: %s; telefone: %s; ano: %d; mes: %d; dia: %d\n",
        i, l->array_contato[i].nome, l->array_contato[i].telefone, l->array_contato[i].ano, l->array_contato[i].mes, l->array_contato[i].dia);
    }
}

/** Informa quantos elementos ha na lista de contatos  */
int tamanho (lista_contatos *l) {
    return l->nodos;
}

/**
 * Adiciona um elemento na lista de contatos. Retorna 1 se
 * a insercao foi bem sucedida e 0 caso contrario
 */
int inserir (lista_contatos *l, contato novo) {
    // insercao no final da lista somente

    // PADRAO:
    /*
    if (tamanho(l) >= l->capacidade) {
        printf("ERRO: tentativa de colocar nodo alem do limite de capacidade do array\n");
        return 0;
    }
    */
    
    // ARRAY DINAMICO:
    if (tamanho(l) >= l->capacidade) {
        l->capacidade = 1.5 * l->capacidade;

        contato* novo_array = (contato*) malloc(l->capacidade * sizeof(contato));

        for (int j=0; j < l->nodos; j++) novo_array[j] = l->array_contato[j];

        free(l->array_contato);
        l->array_contato = novo_array;
    }

    int i = l->nodos;

    l->array_contato[i] = novo;
    l->nodos += 1;
    return 1;
}

/**
 * Remove um elemento em determinada posicao na lista de contatos.
 * Retorna 1 se a remocao foi bem sucedida e 0 caso contrario
 */
int remover (lista_contatos *l, int pos) {
    if (pos < 0 || pos > l->nodos) return 0; // indice alem dos limites da lista
    
    // estamos considerando que a insercao eh somente no final da lista
    for (int i=pos; i < l->nodos-1; i++) {
        l->array_contato[i] = l->array_contato[i+1];
    }

    l->nodos -= 1;
    return 1;
}

/**
 * Retorna a posicao do contato com o nome desejado, ou -1 se nao
 * encontrar
 */
int buscar (lista_contatos *l, char *nome) {
    // busca sequencial
    int i = 0;

    while (i < l->nodos) {
        if (strcmp(nome, l->array_contato[i].nome) == 0) return i; // contato encontrado!
        else i++;
    }

    return -1; // contato nao encontrado apos buscar toda a lista

}

/**
 * Retorna o contato na posicao indicada ou NULL se a
 * posicao for invalida
 */
contato* consultar (lista_contatos *l, int pos) {
    if (pos < 0 || pos > l->nodos) return NULL; // indice alem dos limites da lista

    return &l->array_contato[pos];
}

