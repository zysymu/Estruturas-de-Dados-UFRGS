#include "ui.h"
#include "lista.h"
#include "estatisticas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int preencher(t_lista_enc *l, char* nome_arq){
    FILE* arq;
    arq = fopen(nome_arq, "r");

    if(!arq){
        printf("Erro ao abrir arquivo '%s'!\n", nome_arq);
        return 0;
    }

    char linha[300];    // linha atual lida do arquivo
    char *token;        // trecho atual da linha
    estudante atual;    //tera' os dados de 1 estudante lido


    while(fgets(linha, 300, arq) != NULL) {

        //primeiro valor eh o nome
        token = strtok(linha, ",");
        strcpy(atual.nome, token);

        //segundo valor eh a matricula
        token = strtok(NULL, ",");
        atual.matricula = atoi(token);

        //terceiro valor eh a nota1
        token = strtok(NULL, ",");
        atual.nota1 = atof(token);

        //quarto e ultimo valor eh a nota2
        token = strtok(NULL, ",");
        atual.nota2 = atof(token);

        inserir_ini(l, atual);
    }
    return 1; //tudo ok
}

void trata_inserir(t_lista_enc *l){
    estudante e;
    //scanf(" "); //consome a quebra de linha anterior
    printf("Informe o nome do estudante: ");
    scanf(" %[^\n]s", e.nome);
    //fgets(e.nome, 140, stdin);

    printf("Informe a matricula: ");
    scanf("%d", &e.matricula);

    printf("Informe a nota 1: ");
    scanf("%f", &e.nota1);

    printf("Informe a nota 2: ");
    scanf("%f", &e.nota2);

    if (inserir_ini(l, e)){
        printf("Inserido com sucesso.\n");
    }
    else printf("Erro ao inserir!\n");

}

void trata_remover(t_lista_enc *l){
    int pos;

    printf("Informe a posicao do estudante: ");
    scanf("%d", &pos);

    if (remover(l, pos)) printf("removido com sucesso\n");
    else printf("erro ao remover\n");
}

void trata_buscar(t_lista_enc *l){
    int matricula;
    estudante* e;
    
    printf("Informe a matricula do estudante: ");
    scanf("%d", &matricula);

    if (consultar_matricula(l, matricula)) {
        e = consultar_matricula(l, matricula);

        printf("nome: %s\n", e->nome);
        printf("matricula: %d\n", e->matricula);
        printf("nota1: %f\n", e->nota1);
        printf("nota2: %f\n", e->nota2);
    }
     
    else printf("erro ao buscar\n");   
}

void trata_mostrar(t_lista_enc *l){
    t_nodo *atual;
    printf("Inicio:\n");
    for(atual = l->ini; atual != NULL; atual = atual->prox){
        printf(
           "%s\t%d\t%.2f\t%.2f\n",
           atual->dado.nome, atual->dado.matricula, atual->dado.nota1,
           atual->dado.nota2
        );
    }
    printf("Fim da lista.\n");
}

void trata_estatisticas1(t_lista_enc *l){
    printf("Media da prova1: %.2f\n", media_nota1(l) );
    printf("Desvio Padrao (populacional) da prova1: %.2f\n\n", desv_pad_nota1(l) );

    estudante *melhor, *pior;

    melhor = consultar(l, max_nota1(l));
    pior = consultar(l, min_nota1(l));

    if(melhor != NULL){
        printf("O melhor estudante foi (nome matricula nota1 nota2):\n");
        printf("%s\t%d\t%f\t%f\n\n", melhor->nome, melhor->matricula, melhor->nota1, melhor->nota2);
    }

    if (pior != NULL) {
        printf("O pior estudante foi (nome matricula nota1 nota2):\n");
        printf("%s\t%d\t%f\t%f\n\n", pior->nome, pior->matricula, pior->nota1, pior->nota2);
    }
}

void trata_estatisticas2 (t_lista_enc *l) {
    printf("Media da prova2: %.2f\n", media_nota2(l) );
    printf("Desvio Padrao (populacional) da prova2: %.2f\n\n", desv_pad_nota2(l) );

    estudante *melhor, *pior;

    melhor = consultar(l, max_nota2(l));
    pior = consultar(l, min_nota2(l));

    if(melhor != NULL){
        printf("O melhor estudante foi (nome matricula nota1 nota2):\n");
        printf("%s\t%d\t%f\t%f\n\n", melhor->nome, melhor->matricula, melhor->nota1, melhor->nota2);
    }

    if (pior != NULL) {
        printf("O pior estudante foi (nome matricula nota1 nota2):\n");
        printf("%s\t%d\t%f\t%f\n\n", pior->nome, pior->matricula, pior->nota1, pior->nota2);
    }
}

void trata_comparar_nota1(t_lista_enc *l){
    // cria e inicializa a outra lista
    t_lista_enc outra_turma;
    inicializar(&outra_turma);

    // preenche a outra lista
    char nome_arq[256];
    printf("Digite o arquivo com os dados da outra turma: ");
    scanf(" "); // limpa a entrada, consumindo o enter dado anteriormente - https://stackoverflow.com/a/23666670
    fgets(nome_arq, 256, stdin);
    nome_arq[strcspn(nome_arq, "\r\n")] = 0; //elimina o \n deixado pelo fgets
    if(preencher(&outra_turma, nome_arq) == 0) {
        printf("Lista da outra turma esta' vazia.\n");
    }

    //compara
    int resultado = t_test_ind_nota1(l, &outra_turma);
    if (resultado == -1) {
        printf("Erro. As duas turmas tem o mesmo tamanho?\n");
        return;
    }

    if(resultado == T_TEST_DIFERENTE) { //diferentes
        printf("As diferenca entre as duas turmas e' significativa com relacao 'a nota 1\n");
    }
    else {
        printf("As duas turmas sao semelhantes com relacao 'a nota 1\n");
    }
}

void trata_comparar_nota2(t_lista_enc *l){
    // cria e inicializa a outra lista
    t_lista_enc outra_turma;
    inicializar(&outra_turma);

    // preenche a outra lista
    char nome_arq[256];
    printf("Digite o arquivo com os dados da outra turma: ");
    scanf(" "); // limpa a entrada, consumindo o enter dado anteriormente - https://stackoverflow.com/a/23666670
    fgets(nome_arq, 256, stdin);
    nome_arq[strcspn(nome_arq, "\r\n")] = 0; //elimina o \n deixado pelo fgets
    if(preencher(&outra_turma, nome_arq) == 0) {
        printf("Lista da outra turma esta' vazia.\n");
    }

    //compara
    int resultado = t_test_ind_nota2(l, &outra_turma);
    if (resultado == -1) {
        printf("Erro. As duas turmas tem o mesmo tamanho?\n");
        return;
    }

    if(resultado == T_TEST_DIFERENTE) { //diferentes
        printf("As diferenca entre as duas turmas e' significativa com relacao 'a nota 2\n");
    }
    else {
        printf("As duas turmas sao semelhantes com relacao 'a nota 2\n");
    }
}
