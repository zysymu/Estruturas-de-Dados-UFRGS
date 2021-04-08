#ifndef _LISTA_H_
#define _LISTA_H_


typedef struct estudante {
    char nome[140];
    int matricula;
    float nota1;
    float nota2;
} estudante;

typedef struct st_nodo {
    estudante dado;
    struct st_nodo *prox;
} t_nodo;

typedef struct st_lista_enc {
    t_nodo* ini;
    int tamanho;
} t_lista_enc;

/**
 * Inicializa a lista vazia
 */
void inicializar(t_lista_enc *l);

/**
 * Insere o dado na lista, na posicao indicada.
 * Returna 1 se a insercao der certo e -1 em caso de erro
 */
int inserir(t_lista_enc *l, estudante dado, int pos);

/**
 * Insere o dado na primeira posicao da lista.
 * Retorna 1 em caso de sucesso e -1 em caso de erro
 */
int inserir_ini(t_lista_enc *l, estudante dado);

/**
 * Remove um elemento em uma posicao especifica da lista.
 * Retorna 1 se a remocao der certo ou 0 em caso de erro
 */
int remover(t_lista_enc *l, int pos);

/**
 * Remove o estudante com o numero de matricula especificado.
 * Retorna 1 se a remocao der certo ou 0 em caso de erro
 * (e.g. estudante nao encontrado)
 */
int remover_val(t_lista_enc *l, int matricula);

/**
 * Destroi a lista, liberando todos os nodos
 */
void destruir(t_lista_enc *l);

/**
 * Retorna o estudante na posicao determinada ou NULL
 * se a posicao for invalida
 */
estudante *consultar(t_lista_enc *l, int pos);

/**
 * Retorna o estudante com o numero de matricula especificado
 * ou NULL em caso de erro
 */
estudante *consultar_matricula(t_lista_enc *l, int matricula);

/**
 * Retorna a posicao do estudante com o numero de matricula especificado
 * (o primeiro tem posicao 0)
 * Retorna -1 se nao encontrar.
 */
int buscar(t_lista_enc *l, int matricula);

/**
 * Retorna o numero de elementos na lista
 */
int tamanho(t_lista_enc *l);

#endif // _LISTA_H_
