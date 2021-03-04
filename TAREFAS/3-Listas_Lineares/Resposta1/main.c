#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contato.h"
#include "lista_contatos.h"
#include "io_arquivo.h"

int main()
{
    printf("-----PARTE 1-----\n");
    printf("NECESSARIO UTILIZAR A PARTE `PADRAO` NA FUNCAO `inserir` NO ARQUIVO `lista_contatos.c`");
    lista_contatos amigos, contatos, outros_amigos;
    inicializar(&amigos, 3);

    contato a = {"neil tyson", "+1(699)193265", 1958,10,5};
    contato b = {"serena williams", "+1(369)654963", 1981,9,26};
    contato c = {"edson nascimento", "+55 (11) 35693696", 1940,10,23};
    contato d = {"miguel sapateiro", "+49 (0151) 9876589", 1969,1,3};

    inserir(&amigos, a);
    inserir(&amigos, b);
    inserir(&amigos, c);
    inserir(&amigos, d);

    print_lista(&amigos);

    destruir(&amigos);

    print_lista(&amigos);

    printf("-----PARTE 2-----\n");
    // mesmo com uma capacidade inicial baixa, o arranjo dinamico aumenta a capacidade automaticamente
    inicializar(&contatos, 5);
    preenche_lista(&contatos, "contatos_50.txt");

    print_lista(&contatos);
    
    printf("-----PARTE 3-----\n");
    inicializar(&outros_amigos, 2);

    inserir(&outros_amigos, a);
    inserir(&outros_amigos, b);
    inserir(&outros_amigos, c);
    inserir(&outros_amigos, d);

    print_lista(&outros_amigos);
    remover(&outros_amigos, 1);
    print_lista(&outros_amigos);

    char nome[140];
    int pos;
    contato cont, *cont_ptr;
    cont_ptr = &cont;

    printf("digite o nome do contato para buscar: ");
    // uso do fgets permite formatar para permitir a entrada de espacos
    fgets(nome, 140, stdin);
    // remove possiveis linhas novas
    if ((strlen(nome) > 0) && (nome[strlen (nome) - 1] == '\n')) nome[strlen (nome) - 1] = '\0';

    pos = buscar(&outros_amigos, nome);
    printf("posicao: %d\n", pos);
    cont_ptr = consultar(&outros_amigos, pos);

    printf("nome do contato consultado: %s\n", cont_ptr->nome);

    return 0;
}
