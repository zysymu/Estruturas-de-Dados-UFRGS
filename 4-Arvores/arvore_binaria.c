#include <stdio.h>
#include <stdlib.h>

// TEORIA
/*
- A árvore binária é um tipo especial de árvore onde cada vértice pode possuir no máximo duas sub-árvores: a sub-árvore esquerda e a sub-árvore direita. Assim, o grau de cada vértice (número sub-árvores/filhos) pode ser somente 0, 1 ou 2.
- Nessa mesma ideia também temos a árvore estritamente binária, onde cada vértice possui 0 ou 2 sub-árvores: nenhum nó tem filho único. Os nós internos sempre têm 2 filhos.
- Temos também a árvore binária completa, que é estritamente binária e todos os seus nós-folha estão no mesmo nível. Isso permite calcular o número de nós da árvore binária completa como sendo 2^h - 1, onde h = altura da árvore.
- Há também a árvore binária quase completa, com uma diferença de altura entre as sub-árvores de qualquer nó que é no máximo 1. Se a altura da árvore é D, cada nó folha está no nível D ou no nível D-1.

- A implementação de uma árvore depende do tipo de alocação de memória usada. Nós utilizaremos a alocação dinâmica neste arquivo! Cada nó da árvore é um ponteiro alocado dinamicamente, com um ponteiro para a sub-árvore esquerda, um ponteiro para a sub-árvore direita e o dado que estamos armazenando.
- Também sobre a implementação, as funções que recebem um `Nodo* raiz` poderiam ser alteradas para receberem direto uma árvore binária e então chamarem uma função auxiliar que recebe um Nodo*.

- Muitas operações em árvores binárias necessitam que se percorra todos os nós das sub-árvores, executando então alguma ação em cada nó. Temos de garantir que cada nó é visitada uma única vez, o que gera uma sequência linear denós, cuja ordem depende de como a árvore foi percorrida.
- Há 3 formas principais de percorrer uma árvore: pré-órdem = visita a raiz, o filho a esquerda e o filho a direita; em-ordem = visita filho da esquerda, a raiz e o filho da direita; pós-ordem = vistia o filho da esquerda, o filho da direita e a raiz (é o que fazemos para liberar a árvore, contar número de nós e altura da árvore).
- Considerando a árvore:
      A
     / \
    /   \
   B     C
  / \
 /   \
D     E
     / \
    /   \
   F     G

teremos em pré-ordem: ABDEFGC
teremos em em-ordem: DBFEGAC
teremos em pós-ordem: DFGEBCA

- Nesse arquivo, na parte de inserção e remoção de nós iremos já considerar uma árvore binária de busca, um tipo de árvore binária onde cada nó possui um valor (chave) associado a ele. Esse valor determinada a posição do nó na árvore. Para isso partimos o princípio que não existem valores repetidos.
- Para colocarmos os valores na árvore binária de busca seguimos uma regra: para cada nó pai, todos os valores da sub-árvore esquerda são menores que o nó pai E todos os valores da sub-árvore direita são maiores que o nó pai:
     50
     /\
    /  \
  10    99
  /\
 /  \
5    30
     /\
    /  \
  25    45

a inserção e a remoção de nós da árvore devem ser realizadas respeitando essa regra.
- Aplicações: busca binária, análise de expressões algébricas.

- As principais operações são: (pior caso é com árvores não balanceadas)
Inserção: caso médio = O(log n); pior caso: O(n)
Remoção: caso médio = O(log n); pior caso: O(n)
Consulta: caso médio = O(log n); pior caso: O(n)

*/


////////////////////////////////////////////////////
// ARVORE_BINARIA.h ////////////////////////////////
////////////////////////////////////////////////////

// define o elemento da arvore
typedef struct nodo {
    int dado; // podia ser uma struct ou qualquer outro dado
    struct nodo* esquerda;
    struct nodo* direita;
} Nodo;

// define a arvore
typedef struct arvore_binaria {
    // define um ponteiro para a raiz (inicio da arvore)
    // notar que a raiz aqui aponta para o primeiro no da arvore, e nao eh de fato o primeiro no
    Nodo* raiz;
} Arvore_Binaria;

// inicializa a arvore
void inicializar_arvore (Arvore_Binaria* a);

// libera a arvore
void libera_arvore (Arvore_Binaria* a);

// checa se arvore ta vazia
int checar_arvore_vazia (Nodo* raiz);

// numero de nos da arvore (altura)
int tamanho_arvore (Nodo* raiz);

// checa o numero total de nos que temos na arvore
int total_nos_arvore (Nodo* raiz);

// percorre a arvore em pre-ordem
void percorrer_preordem (Nodo* raiz);

// percorre a arvore em em-ordem
void percorrer_emordem (Nodo* raiz);

// percorre a arvore em pos-ordem
void percorrer_posordem (Nodo* raiz);

// insere elemento na arvore binaria de busca
int inserir_arvore_binaria (Arvore_Binaria* a, int valor);

// remove elemento na arvore binaria de busca
int remover_arvore_binaria (Arvore_Binaria* a, int valor);

// consulta a fila (somente consultamos o elemento no inicio)
//int consulta_fila (Fila* f, aluno* saida);

// printa elementos da arvore
void printa_arvore (Nodo* raiz);

////////////////////////////////////////////////////
// ARVORE_BINARIA.c ////////////////////////////////
////////////////////////////////////////////////////

//#include "ARVORE_BINARIA.h"

void inicializar_arvore (Arvore_Binaria* a) {
    a->raiz = (Nodo*) malloc(sizeof(Nodo));

    if (a->raiz != NULL) // se alocacao deu certo fazer raiz apontar para NULL
        a->raiz = NULL;
}

void libera_no (Nodo* no) {
    if (no == NULL) // caso base
        return;

    libera_no(no->esquerda); // libera todo mundo a esquerda do no
    libera_no(no->direita); // libera todo mundo a direita do no
    free(no); // libera o no
    no = NULL;
}

void libera_arvore (Arvore_Binaria* a) { // Nodo* nesse caso vai ser a raiz (a->raiz)
    if (a->raiz == NULL)
        return; // arvore vazia ja

    libera_no(a->raiz); // libera cada no
    free(a->raiz); // libera raiz
}

int checar_arvore_vazia (Nodo* raiz) {
    if (raiz == NULL) // sem no na arvore
        return 1;

    return 0;
}

int tamanho_arvore (Nodo* raiz) {
    /*
    a funcao percorre a arvore (comecando pela esquerda) e checa o filho da direita e da esquerda
    de cada no. quando chega numa folha, vai ver que tem nenhum filho e retorna zero. a altura em 
    cada no eh a maior altura dos filhos + 1, entao aqui ficaria altura 1. isso eh repetido enquanto
    vai subindo pela arvore, somando a altura que os filhos ja tem
    */

    if (checar_arvore_vazia(raiz))
        return 0;

    int altura_esquerda = tamanho_arvore(raiz->esquerda);
    int altura_direita = tamanho_arvore(raiz->direita);
    
    if (altura_esquerda > altura_direita)
        return (altura_esquerda + 1);
    else
        return (altura_direita + 1);
}

int total_nos_arvore (Nodo* raiz) {
    if (raiz == NULL)
        return 0;

    int altura_esquerda = total_nos_arvore(raiz->esquerda);
    int altura_direita = total_nos_arvore(raiz->direita);

    return (altura_esquerda + altura_direita + 1);
}

void percorrer_preordem (Nodo* raiz) {
    if (checar_arvore_vazia(raiz))
        return;

    if (!checar_arvore_vazia(raiz)) {
        printf("%d\n", raiz->dado);
        percorrer_preordem(raiz->esquerda);
        percorrer_preordem(raiz->direita);
    }
}

void percorrer_emordem (Nodo* raiz) {
    if (checar_arvore_vazia(raiz))
        return;

    if (!checar_arvore_vazia(raiz)) {
        percorrer_preordem(raiz->esquerda);
        printf("%d\n", raiz->dado);
        percorrer_preordem(raiz->direita);
    }
}

void percorrer_posordem (Nodo* raiz) {
    if (checar_arvore_vazia(raiz))
        return;

    if (!checar_arvore_vazia(raiz)) {
        percorrer_preordem(raiz->esquerda);
        percorrer_preordem(raiz->direita);
        printf("%d\n", raiz->dado);
    }
}

int inserir_arvore_binaria (Arvore_Binaria* a, int valor) {
    /*
    para inserir um valor `V` primeiro comparamos ele com a raiz.
    se `V` eh menor que a raiz, vamos para sub-arvore esquerda, senao vamos para a sub-arvore da direita.
    aplicamos isso recursivamente (mas pode ser implementado sem recursao).
    no caso da arvore estar vazia so colocamos o no direto.
    */

    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo == NULL) // caso nao funcionou alocacao 
        return 0;

    // insere o elemento como uma nova folha na arvore (no final)
    novo->dado = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;

    if (checar_arvore_vazia(a->raiz))
        a->raiz = novo;

    else {
        Nodo* atual = a->raiz;
        Nodo* anterior = NULL;

        while (atual != NULL) { // poderiamos tambem percorrer a arvore dos modos anteriores
            anterior = atual;

            if (valor == atual->dado) {
                free(novo);
                return 0; // valor repetido nao eh adicionado
            }

            if (valor > atual->dado)
                atual = atual->direita;
            else
                atual = atual->esquerda;
        }

        if (valor > anterior->dado)
            anterior->direita = novo;
        else
            anterior->esquerda = novo;
    }

    return 1;
}

Nodo* remove_atual (Nodo* atual) {
    Nodo* no1;
    Nodo* no2;

    if (atual->esquerda == NULL) { // sem filho a esquerda, apontar para filho da direita
        no2 = atual->direita;
        free(atual);
        return no2;
    }

    no1 = atual;
    no2 = atual->esquerda;

    while (no2->direita != NULL) {
        no1 = no2;
        no2 = no2->direita;
    }

    if (no1 != atual) {
        no1->direita = no2->esquerda;
        no2->esquerda = atual->esquerda;
    }

    no2->direita = atual->direita;
    free(atual);
    return no2;
}

int remover_arvore_binaria (Arvore_Binaria* a, int valor) {
    /*
    temos 3 tipos de remocao:
    remocao de no folha (sem filho), onde eh so liberar o no e fazer o anterior a ele apontar para NULL.
    remocao de no com 1 filho eh so remover o no atual e fazer o anterior apontar para o filho unico do no.
    remocao de no com 2 filhos temos de pegar o filho da sub-arvore esquerda mais a direita e colocar no local do no que queremos remover.
    */

    Nodo* anterior = NULL;
    Nodo* atual = a->raiz;

    while (atual != NULL) {
        if (valor == atual->dado) { // achou no a ser removido

            if (atual == a->raiz)
                a->raiz = remove_atual(atual);

            else {
                if (anterior->direita == atual)
                    anterior->direita = remove_atual(atual);
                else
                    anterior->esquerda = remove_atual(atual);
            }
        }

        return 1;

        // caso nao achou no, continua procurando
        anterior = atual;
        if (valor > atual->dado)
            atual = atual->direita;
        else
            atual = atual->esquerda;
    }
}

////////////////////////////////////////////////////
// main.c //////////////////////////////////////////
////////////////////////////////////////////////////

int main()
{
    Arvore_Binaria a;
    
    inicializar_arvore(&a);

    inserir_arvore_binaria(&a, 40);
    inserir_arvore_binaria(&a, 30);
    inserir_arvore_binaria(&a, 50);
    inserir_arvore_binaria(&a, 90);
    inserir_arvore_binaria(&a, 45);
    inserir_arvore_binaria(&a, 80);
    inserir_arvore_binaria(&a, 95);
    inserir_arvore_binaria(&a, 20);
    inserir_arvore_binaria(&a, 25);

    // REMOCAO NAO FUNCIONA??????
    remover_arvore_binaria(&a, 20);
    remover_arvore_binaria(&a, 50);
    remover_arvore_binaria(&a, 40);

    percorrer_emordem((&a)->raiz);
}    
