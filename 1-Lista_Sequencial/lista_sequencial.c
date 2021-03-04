#include <stdio.h>
#include <stdlib.h>

// TEORIA
/*
- Chamada de lista estática sequencial ou lista estática linear, é uma lista onde o sucessor de um elemento ocupa a posição física imediatamente depois do elemento.
- A lista é construída sobre um array, de modo que o tamanho do array define o número máximo de elementos na lista.
- A lista é composta de N nodos, onde cada nodo é um dos elementos. Os nodos são criados quando queremos adicionar um novo elemento.

- Vantagens: acesso rápido e direto aos elementos pelo índice; tempo constante para acessar elemento; facilidade em modificar informações.
- Desvantagens: necessária a definição prévia do tamanho do array, que além de limitar o número de elementos da lista pode deixar espaços na memória que não serão usados (pode ser resolvido usando uma lista dinâmica, que com o malloc muda o tamanho do array conforme necessário); dificuldade para inserir um elemento entre outros, que requer deslocar todos os outros elementos para a frente da posição do elemento a ser inserido (o mesmo também ocorre ao remover um elemento).

- Usos: listas pequenas; inserção/remoção só no final da lista (não precisa deslocar elementos); tamanho máximo bem definido; busca é a operação mais frequente.
*/


////////////////////////////////////////////////////
// LISTA_SEQUENCIAL.h //////////////////////////////
////////////////////////////////////////////////////

// exemplo de dado a ser guardado na lista
typedef struct aluno {
    int matricula;
    char nome[30];
    float nota1, nota2, nota3;
} aluno;

// construcao da estrutura lista
typedef struct lista {
    aluno *alunos; // array do dado
    int nodos; // registra numero de nodos
    int tamanho; // registra tamanho do array (tamanho maximo possivel da lista)
} Lista;

// inicializa uma lista
void inicializarLista (Lista *l);

// destroi a lista
void destruirLista (Lista *l);

// checa numero de nodos ocupados
int tamanhoLista (Lista *l);

// checa se lista ta cheia (nao podemos colocar elementos, so retirar)
int checarListaCheia (Lista *l);

// checa se lista ta vazia (nao podemos retirar elementos, so inserir)
int checarListaVazia (Lista *l);

// insere elemento no final da lista
int inserirFinal (Lista *l, aluno novo);

// insere elemento no inicio da lista
int inserirInicio (Lista *l, aluno novo);

// insere elemento de um modo ordenado na lista
int inserirOrdenado (Lista *l, aluno novo);

// remove elemento no final da lista
int removerFinal (Lista *l);

// remove elemento no inicio da lista
int removerInicio (Lista *l);

// remove elemento numa posicao especifica da lista
int removerPosicao (Lista *l, int posicao);

// consulta elemento por posicao
aluno* consultarPosicao (Lista *l, int posicao);

// consulta elemento por conteudo
aluno* consultarConteudo (Lista *l, aluno a);


////////////////////////////////////////////////////
// LISTA_SEQUENCIAL.c //////////////////////////////
////////////////////////////////////////////////////

//#include "LISTA_SEQUENCIAL.h"

void inicializarLista (Lista *l, int tamanho) {
    l->tamanho = tamanho;

    // usar malloc para criar array de tamanho `tamanho`
    l->alunos = (aluno*) malloc(tamanho * sizeof(aluno));

    if (l->alunos == NULL) {     
        printf("\nERRO: memoria nao alocada no malloc\n"); 
        exit(0); 
    } 

    // inicializamos a lista colocando zero nodos nela.
    // quando queremos adicionar um elemento, iremos criar um nodo e colocar o elemento
    l->nodos = 0;
}


void destruirLista (Lista *l) {
    free(l); // numa lista dinamica seria necessario mais do que so um `free`
}


int tamanhoLista (Lista *l) {
    if (l->nodos < 0) return -1; // simboliza um erro

    return l->nodos;
}


int checarListaCheia (Lista *l) {
    if (l->nodos < 0) return -1;

    return (l->nodos == l->tamanho);
}


int checarListaVazia (Lista *l) {
    if (l->nodos < 0) return -1;

    return (l->nodos == 0);
}


int inserirFinal (Lista *l, aluno novo) {
    if (checarListaCheia(l)) {
        printf("\nERRO: tentativa de colocar nodo alem do limite de capacidade do array\n");    
        return -1;
    }

    l->alunos[l->nodos] = novo;
    l->nodos++;
    return 1; // sucesso
}


int inserirInicio (Lista *l, aluno novo) {
    if (checarListaCheia(l)) {
        printf("\nERRO: tentativa de colocar nodo alem do limite de capacidade do array\n");    
        return -1;
    }

    for (int i=l->nodos-1; i>=0; i--) { 
        // esse l->nodos - 1 eh por causa do modo como foi feita a implementacao da lista.
        // l->nodos eh a quantidade, onde uma lista com 1 elemento tem l->nodos == 1.
        // quando queremos adicionar um novo elemento colocamos ele na posicao l-> nodos ate.
        // se uma lista tem 3 nodos ocupados, ela tera as posicoes de 0 a 2 ocupadas, entao precisamos subtrair 1 do l->nodos pra conseguir as posicoes dos elementos.
        l->alunos[i+1] = l->alunos[i];
    }

    l->alunos[0] = novo;
    l->nodos++;
    return 1;
}


int inserirOrdenado (Lista *l, aluno novo) {
    if (checarListaCheia(l)) {
        printf("\nERRO: tentativa de colocar nodo alem do limite de capacidade do array\n");    
        return -1;
    }

    int k, i = 0;

    // percorre toda a lista comparando o numero de matricula do aluno novo com o numero de matricula de cada aluno ja inserido.
    // so sai do loop quando a matricula do aluno novo eh maior que a matricula do ultimo aluno na lista que foi comparado com ele.
    while (i < l->nodos && l->alunos[i].matricula < novo.matricula) i++;

    // move todos os alunos a direita da posicao onde o novo aluno ficara para uma posicao a frente
    for (k=l->nodos-1; k>i; k--) {
        l->alunos[k+1] = l->alunos[k];
    }

    l->alunos[i] = novo;
    l->nodos++;
    return 1;
}


int removerFinal (Lista *l) {
    if (checarListaVazia(l)) {
        printf("\nERRO: tentativa de remover nodo em lista vazia\n");    
        return -1;
    }

    l->nodos--; // deixa o elemento inacessivel pela lista
    return 1;
}


int removerInicio (Lista *l) {
    if (checarListaVazia(l)) {
        printf("\nERRO: tentativa de remover nodo em lista vazia\n");    
        return -1;
    }

    for (int i=0; i<l->nodos-1; i++) {
        l->alunos[i] = l->alunos[i+1];
    }

    l->nodos--;
    return 1;
}


int removerPosicao (Lista *l, int posicao) {
    if (checarListaVazia(l)) {
        printf("\nERRO: tentativa de remover nodo em lista vazia\n");    
        return -1;
    }

    else if (posicao < 0 || posicao > l->nodos) {
        printf("\nERRO: tentativa de remover numa posicao alem da lista\n");    
        return -1; 
    } 

    for (int i=posicao; i<l->nodos-1; i++) {
        l->alunos[i] = l->alunos[i+1];
    }

    l->nodos--;    
    return 1;

}


aluno* consultarPosicao (Lista *l, int posicao) {
    if (posicao < 0 || posicao > l->nodos) {
        printf("\nERRO: tentativa de acessar numa posicao alem da lista\n");    
        return NULL; 
    } 

    return &l->alunos[posicao];
}


aluno* consultarConteudo (Lista *l, aluno a) {
    int i = 0;  
    while (i < l->nodos && l->alunos[i].matricula != a.matricula) i++;

    if (i == l->nodos) return NULL;

    return &l->alunos[i];
}


////////////////////////////////////////////////////
// main.c //////////////////////////////////////////
////////////////////////////////////////////////////

int main()
{
    Lista l;
    inicializarLista(&l, 10);
}
