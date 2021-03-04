#ifndef IO_ARQUIVO_H
#define IO_ARQUIVO_H

#include "lista_contatos.h"

/**
  * Preenche a lista a partir dos dados contidos em um arquivo de texto
  * com o nome especificado.
  * Cada linha do arquivo deve conter: nome,telefone,ano,mes,dia
  */
void preenche_lista(lista_contatos* l, char* nome_arquivo);


#endif
