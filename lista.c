#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionarios.h"

typedef struct lista {
  Funcionario funcionario;
  struct lista *proximo;
} Lista;

Lista* cria_lista(){
  return NULL;
}

/*
void push(Lista *lista, char* ficha){
  //Criando novo funcionario
  Lista* novo = malloc(sizeof(Lista));
  preencherFuncionario(&(novo->funcionario), ficha);
  novo->proximo = NULL;

  //Inserindo o funcionario na lista
  if(lista){
    Lista* temp = lista;

    while(temp->proximo){
      temp = temp->proximo;
    }

    temp->proximo = novo;
  } else{
    lista = novo;
  }
}
*/

void mostrar_lista(Lista* lista){
  Lista* temp = lista;
  while(temp){
    mostrar_funcionario(temp->funcionario);
    temp = temp->proximo;
  }
}

Lista* push_front(Lista *lista, char *ficha) {
  Lista* novo = (Lista *) malloc(sizeof(Lista));
  preencherFuncionario(&(novo->funcionario), ficha);
  novo->proximo = lista;
  lista = novo;
}

void exportar_csv(Lista * lista, char *nome_do_arquivo){
    FILE *out;
    if((out = fopen(nome_do_arquivo, "w")) == NULL){
        printf("Arquivo nao foi exportado\n");
    }
    else{
        //fprintf(out, "nome, funcao, cpf, nascimento\n"); //Cabecalho do csv
        while(lista){
        	char *palavra = funcionario_para_string(lista->funcionario);
			fwrite(palavra, sizeof(char), strlen(palavra), out);
        	fprintf(out, "\n");
        	lista = lista->proximo;
		}
        fclose(out);   
    }
}

//Nesse você passa o endereco da Lista
void importar_csv(Lista ** endereco_lista, char * nome_do_arquivo){
    FILE * in;
    if((in = fopen(nome_do_arquivo, "r")) == NULL){
        printf("Arquivo nao foi lido, talvez o nome esteja errado ou ele nao exista\n");
    }
    else{
		Lista * lista = *endereco_lista;
	    
		int tamanho_string = 200;
		char linha[tamanho_string];
		
		while (fgets(linha, tamanho_string, in)){
		    linha[strlen(linha) - 1] = '\0';
		    char * saida = malloc(sizeof(char) * (strlen(linha)+1) );
		    strcpy(saida, linha);
		    
		    lista = push_front(lista, saida);
		}
		fclose(in);
		
		*endereco_lista = lista;
	}
}

//Nesse outro você coloca Lista p = importar_csv_retorno(p, "nome_do_arquivo")
Lista * importar_csv_retorno(Lista * lista, char * nome_do_arquivo){
    FILE * in;
    if((in = fopen(nome_do_arquivo, "r")) == NULL){
        printf("Arquivo nao foi lido, talvez o nome esteja errado ou ele nao exista\n");
        return (Lista *) NULL;
    }
    
	int tamanho_string = 200;
	char linha[tamanho_string];
	
	while (fgets(linha, tamanho_string, in)){
	    linha[strlen(linha) - 1] = '\0';
	    char * saida = malloc(sizeof(char) * (strlen(linha)+1) );
	    strcpy(saida, linha);
	    
	    lista = push_front(lista, saida);
	}
	fclose(in);
	
	return (Lista *) lista;
}

/*
void append_csv(Funcionario * lista, char * nome_do_arquivo, int limiteMenor, int limiteMaior){
    FILE * a;
    if((a = fopen(nome_do_arquivo, "a")) == NULL){
        printf("Algo deu errado ao concatenar arquivos\n");
    }
    else{
        int i;
        for(i=limiteMenor; i<limiteMaior; i++){
            char *palavra = Funcionario_para_string(&lista[i]);
            if(palavra){
                fwrite(palavra, sizeof(char), strlen(palavra), a);
                fprintf(a, "\n");
            }
        }
        fclose(a);
    }
}
*/
