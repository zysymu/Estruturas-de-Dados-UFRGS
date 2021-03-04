#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io_arquivo.h"
#include "lista_contatos.h"

#define BUFFER_SIZE 1000

void preenche_contato(contato* novo, char* dados) {
	char* token = strtok(dados, ",");

	int i = 0;
	while ( token != NULL ) {
		switch(i) {
			case 0:
				strcpy(novo->nome, token);
				break;
			case 1:
				strcpy(novo->telefone, token);
				break;
			case 2:
				novo->ano = atoi(token);
				break;
			case 3:
				novo->mes = atoi(token);
				break;
			case 4:
				novo->dia = atoi(token);
				break;
		}
		token = strtok(NULL, ",");
		i++;
	}
}

void preenche_lista(lista_contatos* l, char* nome_arquivo) {
	FILE* arq = fopen(nome_arquivo, "r");
	char* buffer = (char*) malloc(BUFFER_SIZE * sizeof(char));
	char c;
	int i = 0;
	contato novo;
	while ( (c = fgetc(arq)) != EOF ) {
		if (c == '\n') {
			buffer[i] = '\0';
			preenche_contato(&novo, buffer);
			inserir(l, novo);
			i = 0;
		} else {
			buffer[i] = c;	
			i++;
		}
	}
	free(buffer);
	fclose(arq);
}
