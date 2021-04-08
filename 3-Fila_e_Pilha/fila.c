#include <stdio.h>
#include <stdlib.h>

// TEORIA
/*
- A fila (queue) é uma sequência de elementos do mesmo tipo (parecido com listas). Esses elementos possuem estrutura interna abstraída.
- Podemos pensar na fila como uma fila na vida real: ela tem um início e um fim e anda no sentido do final para o início. Então um novo elemento é colocado no final da lista e anda por ela até chegar no início, onde é então removido.
- Inserções e exclusões de elementos ocorrem sempre nas extremidades da fila. A inserção é só de um lado (final) e a exclusão é só do outro lado (início).
- A fila segue uma estrutura FIFO: First In First Out.

- Aplicações: controle de fluxo, recursos compartilhados (transações de banco de dados, documentos a serem impressos).

- Em uma fila iremos então inserir um elemento no final (somente), remover um elemento do início (somente) e acessar somente o elemento que está no início da fila.

- Alocação estática: espaço de memória é alocado no momento da compilação. Exige a definição do número máximo de elementos da fila. Temos elementos consecutivos na memória (array).
- Alocação dinâmica: espaço de memória é alocado em tempo de execução. A fila cresce a medida que novos elementos são armazenados e diminui à medida que elementos são removidos. Acesso encadeado: cada elemento pode estar em uma área distinta da memória, e para acessar um elemento temos de percorrer todos os seus antecessores na fila.

- Nesse arquivo utilizamos a implementação dinâmica!
*/


////////////////////////////////////////////////////
// FILA.h //////////////////////////////////////////
////////////////////////////////////////////////////

typedef struct aluno {
    int matricula;
    char nome[30];
    float nota1, nota2, nota3;
} aluno;

// define o elemento da fila
typedef struct nodo {
    aluno al;
    struct nodo* prox;
} Nodo;

// define a fila
typedef struct fila {
    // nota-se que os elementos sao inseridos no final e removidos no inicio
    Nodo* inicio;
    Nodo* final;
} Fila; 

// inicializa a fila
void inicializar_fila (Fila* f);

// libera a fila
void libera_fila (Fila* f);

// numero de nodos da fila
int tamanho_fila (Fila* f);

// checa se fila ta cheia
int checar_fila_cheia (Fila* f);

// checa se fila ta vazia
int checar_fila_vazia (Fila* f);

// insere elemento na fila (insercao eh sempre no final!!!)
int inserir_fila (Fila* f, aluno novo);

// remove elemento na fila (remocao eh sempre no inicio!!!)
int remover_fila (Fila* f);

// consulta a fila (somente consultamos o elemento no inicio)
int consulta_fila (Fila* f, aluno* saida);

// printa elementos da fila
void printa_fila (Fila* f);

////////////////////////////////////////////////////
// FILA.c //////////////////////////////////////////
////////////////////////////////////////////////////

//#include "FILA.h"

void inicializar_fila (Fila* f) {
    if (f != NULL) { // caso alocacao deu certo
        f->inicio = NULL;
        f->final = NULL;
    }
}

void libera_fila (Fila* f) {
    if (f != NULL) { // se fila nao estiver vazia
        Nodo* nodo_atual;

        while (f->inicio != NULL) { // pois removemos do inicio
            nodo_atual = f->inicio;
            f->inicio = f->inicio->prox;
            free(nodo_atual);
        }
        
        free(f);
    }
}

int tamanho_fila (Fila* f) {
    if (f == NULL) return 0;

    int tamanho = 0;
    Nodo* nodo_atual = f->inicio;

    while (nodo_atual != NULL) {
        tamanho++;
        nodo_atual = nodo_atual->prox;
    }

    return tamanho;
}

int checar_fila_cheia (Fila* f) {
    return 0; // implementacao dinamica nunca enche
}

int checar_fila_vazia (Fila* f) {
    if (f == NULL) return 1;
    if (f->inicio == NULL) return 1; // 

    return 0;
}

int inserir_fila (Fila* f, aluno novo) {
    if (f == NULL) return 0;

    // aloca memoria pro elemento
    Nodo* nodo_novo = (Nodo*) malloc(sizeof(Nodo));
    if (nodo_novo == NULL) return 0;

    nodo_novo->al = novo;
    nodo_novo->prox = NULL;

    // caso de lista vazia
    if (f->final == NULL) f->inicio = nodo_novo;

    // caso de lista com elementos
    else f->final->prox = nodo_novo;

    f->final = nodo_novo;
    return 1;
}

int remover_fila (Fila* f) {
    if (f == NULL) return 0;

    // nao se pode remover de lista vazia
    if (f->inicio == NULL) return 0;

    Nodo* nodo_removido = f->inicio;
    f->inicio = nodo_removido->prox;

    // se fila fica vazia
    if (f->inicio == NULL) f->final = NULL;

    free(nodo_removido);
    return 1;    
}

int consulta_fila (Fila* f, aluno* saida) {
    if (f != NULL || f->inicio != NULL) {
        return 0;
    }

    *saida = f->inicio->al;
    return 1;
}

void printa_fila (Fila* f) {
    Nodo* atual = f->inicio;

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
    Fila f;

    aluno a = {1111, "Ann Anny", 10., 10., 9.5};
    aluno b = {1115, "Bob Bobby", 6., 8., 5.};
    aluno c = {1120, "Chase Chassy", 7., 7.6, 10.};
    aluno d = {1117, "Dan Danny", 4., 1., 0.};
    
    inicializar_fila(&f);

    inserir_fila(&f, a);
    inserir_fila(&f, b);
    inserir_fila(&f, c);
    inserir_fila(&f, d);

    printf("%d\n", tamanho_fila(&f));
    printa_fila(&f);

    remover_fila(&f);
    remover_fila(&f);

    printf("%d\n", tamanho_fila(&f));
    printa_fila(&f);
}    
