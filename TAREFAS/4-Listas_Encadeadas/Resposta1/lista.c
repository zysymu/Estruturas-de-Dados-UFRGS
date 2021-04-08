#include "lista.h"
#include <stdlib.h>

void inicializar(t_lista_enc *l){
    l->ini = NULL;
    l->tamanho = 0;
}

int inserir(t_lista_enc *l, estudante dado, int pos){
    int i = 0;
    t_nodo *novo = NULL; // Ponteiro para novo elemento
    t_nodo *ant = NULL; // Aux. para a posição anterior
    t_nodo *atual = l->ini; // Aux. para percorrer a lista
    novo = (t_nodo *)malloc(sizeof(t_nodo )); // Aloca um novo nodo
    if (novo == NULL) {
        return 0; // Falta de memoria!
    }
    novo->dado = dado;

    // Procura a posição de insercao
    while((atual != NULL) && i<pos) {
            ant = atual;
            atual = atual->prox;
        i++;
    }

    // Encadeia o elemento
    if (ant == NULL) { //Insere na primeira posição (também para lista vazia)
        novo->prox = l->ini;
        l->ini = novo;
    } else { // Insere no meio (ou final) da lista
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    l->tamanho++;
    return 1; // Sucesso!

}

int inserir_ini(t_lista_enc *l, estudante dado){
    return inserir(l, dado, 0);
}

int remover(t_lista_enc *l, int pos){
    int i = 0;
    t_nodo *ant = NULL; // Aux. para a posicao anterior
    t_nodo *atual = l->ini; // Aux. para percorrer a lista

    // Procura o elemento na lista
    while(atual != NULL && i < pos) {
        ant = atual;
        atual = atual->prox;
        i++;
    }
    if(atual == NULL) return 0; //nao achou

    if(ant == NULL) { // Vai remover o primeiro elemento
        l->ini = atual->prox;
    }
    else {          // Vai remover do meio ou do final
        ant->prox = atual->prox;
    }
    free(atual); // Libera a memoria alocada

    l->tamanho--;
    return 1;

}


int remover_val(t_lista_enc *l, int matricula){
    return remover(l, buscar(l, matricula));
}

void destruir(t_lista_enc *l){
    while(remover(l, 0));
}

estudante* consultar(t_lista_enc *l, int pos){
    int i = 0;
    t_nodo *atual = l-> ini; // Aux. para percorrer a lista

    while (atual != NULL && i<pos) {
        atual = atual->prox;
        i++;
    }
    if (atual != NULL) return &atual->dado;
    else return NULL;

}

estudante* consultar_matricula(t_lista_enc *l, int matricula){
    t_nodo *atual = l->ini; // Aux. para percorrer a lista

    while (atual != NULL && atual->dado.matricula != matricula) {
        atual = atual->prox;
    }
    if (atual != NULL) return &atual->dado;
    else return NULL;
}

int buscar(t_lista_enc *l, int matricula){
    t_nodo *atual = l->ini; // Aux. para percorrer a lista
    int pos = 0; //posicao do elemento atual

    while (atual != NULL && atual->dado.matricula != matricula) {
        atual = atual->prox;
        pos++;
    }
    if (atual != NULL) return pos; //encontrado
    else return -1; //nao encontrado
}

int tamanho(t_lista_enc *l){
    return l->tamanho;
}

