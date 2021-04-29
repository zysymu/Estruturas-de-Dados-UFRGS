#include <stdio.h>
#include <stdlib.h>

// TEORIA
/*
- A pilha (stack) é uma sequência de elementos do mesmo tipo (parecido com as filas). Esses elementos possuem estrutura interna abstraída.
- Podemos pensar na pilha como uma pilha de livros um elemento sobre o outro, com o acesso sendo sempre no topo da pilha.
- As inserções e exclusões de elementos ocorrem apenas no início da lista então (topo da pilha).
- A pilha segue uma estrutura LIFO: Last In First Out.

- Aplicações: análise de expressão matemática, converter número decimal para binário.

- Em uma pilha iremos então inserir um elemento no início (topo) somente, remover um elemento do início somente e acessar somente o elemento do início.

- Alocação estática: espaço de memória é alocado no momento da compilação. Exige a definição do número máximo de elementos da pilha. Temos elementos consecutivos na memória (array).
- Alocação dinâmica: espaço de memória é alocado em tempo de execução. A pulha cresce a medida que novos elementos são armazenados e diminui à medida que elementos são removidos. Acesso encadeado: cada elemento pode estar em uma área distinta da memória, e para acessar um elemento temos de percorrer todos os seus antecessores na fila.

- Nesse arquivo utilizamos a implementação dinâmica!
*/


////////////////////////////////////////////////////
// PILHA.h /////////////////////////////////////////
////////////////////////////////////////////////////

// define o elemento da pilha
typedef struct nodo {
    int al;
    struct nodo* prox;
} Nodo;

// define a pilha
typedef struct pilha {
    // aqui definimos um ponteiro para o topo da pilha
    Nodo* topo;
} Pilha; 

// inicializa a pilha
void inicializar_pilha (Pilha* p);

// libera a pilha
void libera_pilha (Pilha* p);

// numero de nodos da pilha
int tamanho_pilha (Pilha* p);

// checa se fila ta pilha
int checar_pilha_cheia (Pilha* p);

// checa se fila ta pilha
int checar_pilha_vazia (Pilha* p);

// insere elemento na pilha (insercao eh sempre no topo!!!)
int inserir_pilha (Pilha* p, int novo);

// remove elemento na pilha (remocao eh sempre no topo!!!)
int remover_pilha (Pilha* p);

// printa elementos da pilha
void printa_pilha (Pilha* p);

////////////////////////////////////////////////////
// PILHA.c /////////////////////////////////////////
////////////////////////////////////////////////////

//#include "PILHA.h"

void inicializar_pilha (Pilha* p) {
    if (p != NULL) {
        p->topo = NULL;
    }
}

void libera_pilha (Pilha* p) {
    if (p != NULL) {
        Nodo* nodo_atual;

        while (p->topo != NULL) {
            nodo_atual = p->topo;
            p->topo = p->topo->prox;
            free(nodo_atual);
        }
        
        free(p);
    }
}

int tamanho_pilha (Pilha* p) {
    if (p == NULL) return 0;

    int tamanho = 0;
    Nodo* nodo_atual = p->topo;

    while (nodo_atual != NULL) {
        tamanho++;
        nodo_atual = nodo_atual->prox;
    }

    return tamanho;
}

int checar_pilha_cheia (Pilha* p) {
    return 0;
}

int checar_pilha_vazia (Pilha* p) {
    if (p == NULL) return 1;
    if (p->topo == NULL) return 1; // 

    return 0;
}

int inserir_pilha (Pilha* p, int novo) {
    if (p == NULL) return 0;
    
    Nodo* nodo_novo = (Nodo*) malloc(sizeof(Nodo));
    if (nodo_novo == NULL) return 0;

    nodo_novo->al = novo;
    nodo_novo->prox = p->topo;

    p->topo = nodo_novo;
    return 1;
}

int remover_pilha (Pilha* p) {
    if (p == NULL) return 0;
    if (checar_pilha_vazia(p)) return 0;

    Nodo* nodo_removido = p->topo;
    p->topo = nodo_removido->prox;
    
    free(nodo_removido);
    return 1;
}

void printa_pilha (Pilha* p) {
    Nodo* atual = p->topo;

    while (atual != NULL) {
        printf("%d, ", atual->al);
        atual = atual->prox;
    }
}


////////////////////////////////////////////////////
// main.c //////////////////////////////////////////
////////////////////////////////////////////////////

int main()
{
    Pilha p1;
    
    inicializar_pilha(&p1);

    inserir_pilha (&p1, 2); //b
    printf("\n==============\n");
    printa_pilha(&p1);

    printf("\n==============\n"); //cheia
    printa_pilha(&p1);

    inserir_pilha (&p1, 5); //s
    printf("\n==============\n");
    printa_pilha(&p1);

    inserir_pilha (&p1, 1); //a
    printf("\n==============\n");
    printa_pilha(&p1);
    
    inserir_pilha (&p1, 3); // c
    printf("\n==============\n");
    printa_pilha(&p1);

    remover_pilha(&p1);
    printf("\n==============\n");
    printa_pilha(&p1);

    remover_pilha(&p1);
    printf("\n==============\n");
    printa_pilha(&p1);

    inserir_pilha (&p1, 8); //h
    printf("\n==============\n");
    printa_pilha(&p1);

    inserir_pilha (&p1, 4); //d
    printf("\n==============\n");
    printa_pilha(&p1);

    inserir_pilha (&p1, 6); //f
    printf("\n==============\n");
    printa_pilha(&p1);

    remover_pilha(&p1);
    printf("\n==============\n");
    printa_pilha(&p1);

    inserir_pilha (&p1, 11); //n
    printf("\n==============\n");
    printa_pilha(&p1);

    inserir_pilha (&p1, 2); //b
    printf("\n==============\n");
    printa_pilha(&p1);

    printf("\n==============\n");
    printa_pilha(&p1); // cheia

    remover_pilha(&p1);
    printf("\n==============\n");
    printa_pilha(&p1);

    inserir_pilha (&p1, 10); //m
    printf("\n==============\n");
    printa_pilha(&p1);

    remover_pilha(&p1);
    printf("\n==============\n");
    printa_pilha(&p1);

    remover_pilha(&p1);
    printf("\n==============\n");
    printa_pilha(&p1);

    remover_pilha(&p1);
    printf("\n==============\n");
    printa_pilha(&p1);

    printf("\n==============\n");
    printa_pilha(&p1); // vazia
}    
