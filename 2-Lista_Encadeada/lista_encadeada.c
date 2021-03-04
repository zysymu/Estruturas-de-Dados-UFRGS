#include <stdio.h>
#include <stdlib.h>

// TEORIA
/*
- Estamos tratando da lista encadeada DINÂMICA!
- Também chamada de lista ligada, é um tipo de lista onde cada elemento aponta para o seu sucessor.
- Diferente da lista sequencial, os dados ocupam qualquer posição disponível na memória: a ordem dos elementos da lista não necessariamente coincide com a posição física deles na memória.
- Usamos um ponteiro especial para o primeiro elemento da lista e uma indicação do final da lista.
- Cada elemento (nodo) da lista é composto de um dado e um ponteiro. O ponteiro aponta para o elemento seguinte da lista.
- O último elemento da lista irá apontar para um NULL.

- Cada nodo será tratado como um ponteiro, sendo alocado dinamicamente a medida que os dados são inseridos.
- Para guardar o primeiro nodo da lista usamos um ponteiro para ponteiro. Fazemos isso porque o ponteiro para ponteiro guarda a informação de um ponteiro, e como cada nodo será um ponteiro, estaremos apontando para um ponteiro.
- Podemos assim mudar o nodo de começo da lista mudando para quem o ponteiro para o ponteiro aponta.

- Vantagens: melhor utilização de memória (não alocamos posições ociosas, que estão alocadas mas não estão sendo usadas), alocando o quanto precisamos de memória a cada passo; não é necessário movimentar os elementos em inserção e remoção, só mudamos para onde os elementos apontam.
- Desvantagens: acesso indireto aos elementos; necessário percorrer a lista para acessar um elemento (é necessário usar o ponteiro do elemento 1 para chegar no elemento 2, o ponteiro do elemento 2 para chegar no elemento 3, etc.).

- Usos: quando não podemos garantir um espaço mínimo para a execução; quando inserção/remoção em lista ordenada forem as operações mais frequentes (inesrção ordenada pode ser no início, meio ou final, o que requer vários deslocamentos).
*/


////////////////////////////////////////////////////
// LISTA_ENCADEADA.h ///////////////////////////////
////////////////////////////////////////////////////

typedef struct aluno {
    int matricula;
    char nome[30];
    float nota1, nota2, nota3;
} aluno;

// define como um elemento da lista encadeada eh
typedef struct nodo { 
    aluno al; // campo de dado
    struct nodo* prox; // campo do ponteiro que aponta para o proximo elemento
} Nodo;

// define a lista encadeada
typedef struct lista {
    Nodo* inicio; // um ponteiro para o primeiro elemento
} Lista;

// inicializa lista
void inicializarLista (Lista* l);

// liberar lista
void liberaLista (Lista* l);

// numero de nodos da lista
int tamanhoLista (Lista* l);

// checa se lista ta cheia
int checarListaCheia (Lista* l);

// checa se lista ta vazia
int checarListaVazia (Lista* l);

// insere elemento no inicio da lista
int inserirInicio (Lista *l, aluno novo);

// insere elemento no final da lista
int inserirFinal (Lista *l, aluno novo);

// insere elemento de um modo ordenado na lista
int inserirOrdenado (Lista *l, aluno novo);

// remove elemento no inicio da lista
int removerInicio (Lista *l);

// remove elemento no final da lista
int removerFinal (Lista *l);

// remove elemento numa posicao especifica da lista
int removerPosicao (Lista *l, int posicao);

// consulta elemento por posicao
aluno* consultarPosicao (Lista *l, int posicao);

// consulta elemento por conteudo
aluno* consultarConteudo (Lista *l, aluno a);

// printa info de cada elemento da lista
void printLista(Lista* l);

////////////////////////////////////////////////////
// LISTA_ENCADEADA.c ///////////////////////////////
////////////////////////////////////////////////////

//#include "LISTA_ENCADEADA.h"

void inicializarLista (Lista* l) {
    // alocamos memoria para o primeiro nodo da lista
    l->inicio = (Nodo*) malloc(sizeof(Nodo));
    
    if (l->inicio != NULL) { // caso alocacao deu certo
        l->inicio = NULL; // inicio aponta pra NULL, pois temos uma lista vazia    
    }
}

void liberaLista (Lista* l) {
    if (l->inicio != NULL) { // se lista nao esta vazia
        Nodo* nodo_atual = l->inicio;
        Nodo* nodo_prox;

        while(nodo_atual != NULL) {
            nodo_prox = nodo_atual->prox;
            free(nodo_atual);
            nodo_atual = nodo_prox;
        }
    }
    
    l->inicio = NULL; // libera o ponteiro para o primeiro elemento
}

int tamanhoLista (Lista* l) {
    int tamanho = 0;
    
    if (l->inicio == NULL) return tamanho; // tamanho zero

    // nao podemos andar com a cabeca da lista (lista->inicio), senao iriamos perder o comeco da lista
    Nodo* atual = l->inicio; // se recebesse uma `Lista l` aqui seria lista.inicio

    while (atual != NULL) {
        tamanho++;
        atual = atual->prox;
    }   

    return tamanho;
}

int checarListaCheia (Lista* l) {
    return -1; // lista dinamica nunca pode estar cheia... exceto se acabar memoria do pc
}

// checa se lista ta vazia
int checarListaVazia (Lista* l) {
    if (l->inicio == NULL) return 1;
    
    return 0;
}

int inserirInicio (Lista* l, aluno novo) {
    Nodo* nodo_novo = (Nodo*) malloc(sizeof(Nodo)); // aloca memoria para novo elemento da lista
    if (nodo_novo == NULL) return -1; // nao foi possivel alocar memoria

    nodo_novo->al = novo; // passa dados

    // faz com que o prox nodo seja o inicio da lista (e por consequencia toda a lista).
    // caso a lista tiver nenhum elemento, faz com que o prox elemento seja NULL
    nodo_novo->prox = l->inicio; 
    l->inicio = nodo_novo; // faz com que o inicio da lista aponte pro novo elemento    

    return 1; // sucesso
}

int inserirFinal (Lista* l, aluno novo) {
    Nodo* nodo_novo = (Nodo*) malloc(sizeof(Nodo));
    if (nodo_novo == NULL) return -1;

    nodo_novo->al = novo;
    nodo_novo->prox = NULL; // pois eh o final da lista

    if (checarListaVazia(l)) { // caso lista vazia, inserir no inicio
        l->inicio = nodo_novo;
    }

    else {
        Nodo* nodo_atual = l->inicio; // funciona como uma contagem de nodos

        while (nodo_atual->prox != NULL) { // enquanto nao chegamos no ultimo nodo (que aponta pra NULL)
            nodo_atual = nodo_atual->prox; // coloca o nodo atual como o nodo proximo
        }

        nodo_atual->prox = nodo_novo; // ultimo nodo aponta pro nodo novo
    }

    return 1; // sucesso

}

int inserirOrdenado (Lista* l, aluno novo) {
    Nodo* nodo_novo = (Nodo*) malloc(sizeof(Nodo));
    if (nodo_novo == NULL) return -1;

    nodo_novo->al = novo;
    
    if (checarListaVazia(l)) { // caso lista vazia, inserir no inicio
        nodo_novo->prox = l->inicio; // com lista vazia, isso eh == NULL
        l->inicio = nodo_novo;
    }

    else {
        // cria nodos auxiliares
        Nodo* nodo_anterior;
        Nodo* nodo_atual = l->inicio;

        while (nodo_atual != NULL && nodo_atual->al.matricula < novo.matricula) {
            // fazer desenho pra ver melhor :v
            nodo_anterior = nodo_atual;
            nodo_atual = nodo_atual->prox;
        }

        nodo_novo->prox = nodo_atual; // novo nodo vai apontar pro prox nodo que tem uma matricula maior que el
        nodo_anterior->prox = nodo_novo; // nodo com uma matricula menor que o novo nodo vai apontar pro novo nodo
    }

    return 1;
}

int removerInicio (Lista *l) {
    if (checarListaVazia(l)) return -1; // nao se pode remover de uma lista vazia

    Nodo* aux = l->inicio;
    l->inicio = aux->prox; 
    free(aux);

    return 1;
}

int removerFinal (Lista *l) {
    if (checarListaVazia(l)) return -1;

    Nodo* nodo_anterior;
    Nodo* nodo_atual = l->inicio;
    
    while (nodo_atual->prox != NULL) {
        nodo_anterior = nodo_atual;
        nodo_atual = nodo_atual->prox;
    }

    if (nodo_atual == l->inicio) { 
        l->inicio = NULL;
    }
    else {
        nodo_anterior->prox = NULL;
        free(nodo_atual);
    }

    return 1;
}

int removerPosicao (Lista *l, int posicao) {
    if (checarListaVazia(l)) return -1;

    Nodo* nodo_anterior;
    Nodo* nodo_atual = l->inicio;
    int i = 0;
    
    while (nodo_atual != NULL && i < posicao) {
        nodo_anterior = nodo_atual;
        nodo_atual = nodo_atual->prox;
        i++;
    }

    if (nodo_atual == l->inicio) { 
        l->inicio = nodo_atual->prox;
    }
    else {
        nodo_anterior->prox = NULL;
        free(nodo_atual);
    }

    return 1; 
}

// para as funcoes de consulta seria melhor ter como entrada um `&aluno`.
// assim seria possivel fazer o retorno de um `int` ao inves de um `aluno*`.
// isso permitiria retornar 1 ou -1 dependendo se a consulta deu certo ou nao.
// seria somente necessario fazer `*aluno = nodo->al` para atualizar o `&aluno` de entrada.
// atualmente, caso a consulta nao for possivel ha o retorno de um NULL, que pode causar
// segmentation fault ao usar junto com um printf!

aluno* consultarPosicao (Lista *l, int posicao) {
    if (posicao < 0 || checarListaVazia(l)) return NULL;

    Nodo* aux = l->inicio;
    int i = 0;

    while (aux != NULL && i < posicao) {
        aux = aux->prox;
        i++;
    }

    return &aux->al;
}

aluno* consultarConteudo (Lista *l, aluno a) {
    Nodo* aux = l->inicio;

    while (aux != NULL && aux->al.matricula != a.matricula) {
        aux = aux->prox;
    }

    return &aux->al;
}

void printLista(Lista* l) {
    Nodo* atual = l->inicio;

    while (atual != NULL) {
        printf("%d, %s, %f, %f, %f\n", atual->al.matricula, atual->al.nome, atual->al.nota1, atual->al.nota2, atual->al.nota3);
        atual = atual->prox;
    }   
}

////////////////////////////////////////////////////
// main.c //////////////////////////////////////////
////////////////////////////////////////////////////

int main()
{
    Lista l;

    aluno a = {1111, "Ann Anny", 10., 10., 9.5};
    aluno b = {1115, "Bob Bobby", 6., 8., 5.};
    aluno c = {1120, "Chase Chassy", 7., 7.6, 10.};
    aluno d = {1117, "Dan Danny", 4., 1., 0.};

    inicializarLista(&l);
    inserirFinal(&l, c);
    inserirInicio(&l, a);
    printLista(&l);
    printf("-------------------\n");

    inserirOrdenado(&l, b);
    printLista(&l);
    printf("-------------------\n");
    inserirOrdenado(&l, d);
    printLista(&l);
    printf("-------------------\n");

    aluno* al = consultarConteudo(&l, b);
    printf("%d\n", al->matricula);
    printf("-------------------\n");

    removerFinal(&l);
    removerFinal(&l);
    printLista(&l);
    printf("-------------------\n");

    al = consultarPosicao(&l, 0);
    printf("%d\n", al->matricula);
    printf("-------------------\n");

    removerPosicao(&l, 0);
    printLista(&l);
    printf("-------------------\n");

    liberaLista(&l);
    printLista(&l);
    printf("-------------------\n");
}
