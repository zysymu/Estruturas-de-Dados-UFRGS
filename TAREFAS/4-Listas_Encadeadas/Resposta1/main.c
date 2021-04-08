#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "ui.h"
#include <string.h>


int main()
{
    char nome_arq[256];
    int opcao; //para o menu de opcoes

    printf("==== TAREFA 5 ====\n");

    t_lista_enc lista;

    printf("Digite o nome do arquivo: ");
    fgets(nome_arq, 256, stdin);    //fgets com stdin le do teclado
    nome_arq[strcspn(nome_arq, "\r\n")] = 0; //elimina o \n deixado pelo fgets

    inicializar(&lista);
    if (preencher(&lista, nome_arq) == 0) {
        printf("Lista nao foi preenchida a partir do arquivo. Iniciando com lista vazia...\n");
    }

    do{ //processa o menu de opcoes
        printf("----------------------------------\n");
        printf("O que deseja fazer?\n");
        printf("1) Inserir novo estudante\n");
        printf("2) Remover estudante\n");
        printf("3) Buscar estudante\n");
        printf("4) Mostrar lista de estudantes\n");
        printf("5) Mostrar estatisticas da nota 1\n");
        printf("6) Mostrar estatisticas da nota 2\n");
        printf("7) Comparar nota 1 com outra turma\n");
        printf("8) Comparar nota 2 com outra turma\n");
        printf("\n0) Sair\n");

        printf("\nDigite opcao: ");
        scanf("%d", &opcao);

        switch(opcao){

        case 1:
            trata_inserir(&lista);
            break;

        case 2:
            trata_remover(&lista);
            break;

        case 3:
            trata_buscar(&lista);
            break;

        case 4:
            trata_mostrar(&lista);
            break;

        case 5:
            trata_estatisticas1(&lista);
            break;

        case 6:
            trata_estatisticas2(&lista);
            break;

        case 7:
            trata_comparar_nota1(&lista);
            break;

        case 8:
            trata_comparar_nota2(&lista);
            break;
        }

    } while(opcao != 0);

    printf("FIM\n");
    return 0;
}
