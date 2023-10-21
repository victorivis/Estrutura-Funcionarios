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

void push_front(Lista ** endereco_lista, char *ficha) {
  //Lista* lista = *endereco_lista;
  Lista* novo = (Lista *) malloc(sizeof(Lista));
  preencherFuncionario(&(novo->funcionario), ficha);
  novo->proximo = *endereco_lista;
  
  *endereco_lista = novo;
}

Lista* push_front_retorno(Lista *lista, char *ficha) {
  Lista* novo = (Lista *) malloc(sizeof(Lista));
  preencherFuncionario(&(novo->funcionario), ficha);
  novo->proximo = lista;
  lista = novo;
  return lista;
}

void push_back(Lista **endereco_lista, char *ficha){
	Lista* novo = (Lista *) malloc(sizeof(Lista));
  	preencherFuncionario(&(novo->funcionario), ficha);
  	novo->proximo = NULL;
  	
  	Lista* temp = *endereco_lista;
  	if(temp){
  		while(temp->proximo){
  			temp = temp->proximo;
		}
		temp->proximo = novo;
	}
	else{
		*endereco_lista = novo;
	}
}

/*
Lista* pop_n(Lista *lista, int destino){
	int atual=0;
	if(lista){
		if(destino != 0){
		while(atual != destino-1){
			if(lista->proximo == NULL){
				printf("Impossivel deletar, destino nao existe\n");
				return lista;
			}
			lista = lista->proximo;
		}
		
		Lista * temp = lista->proximo;
		lista->proximo = temp->proximo;
		
		free(temp->funcionario.cpf);
		free(temp->funcionario.nome);
		temp->proximo = NULL;
		free(temp);
		}
		else{
			Lista * temp = lista->proximo;
			//lista->proximo = temp->proximo;
			
			free(lista->funcionario.cpf);
			free(lista->funcionario.nome);
			//temp->proximo = NULL;
			free(lista);
		}
	}
	else{
		printf("Lista vazia, impossivel deletar\n");
		return lista;
	}
	
}
*/

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
		    
		    push_front(&lista, saida);
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
	    
	    push_front(&lista, saida);
	}
	fclose(in);
	
	return (Lista *) lista;
}


void append_csv(Lista ** endereco_lista, char * nome_do_arquivo){
    FILE * a;
    if((a = fopen(nome_do_arquivo, "a")) == NULL){
        printf("Algo deu errado ao concatenar arquivos\n");
    }
    else{
    	Lista *lista = *endereco_lista;
    	while(lista){
            char *palavra = funcionario_para_string(lista->funcionario);
            if(palavra){
                fwrite(palavra, sizeof(char), strlen(palavra), a);
                fprintf(a, "\n");
            }
            lista = lista->proximo;
        }
        fclose(a);
    }
}


void pop_n(Lista **endereco_lista, int destino){
	int atual=0;
	Lista *lista = *endereco_lista;
	if(lista){
		if(destino){
			while(lista && atual!=destino-1){
				lista = lista->proximo;
			}
			if(lista){
				Lista *temp = lista->proximo;
				lista->proximo = temp->proximo;
				
				free(temp);			
			}
			else{
				printf("Remocao impossivel. Funcionario nao existe.\n");
			}
		}
		else{
			//printf("Sucesso\n");
			Lista *temp = lista;
			lista = lista->proximo;
			free(temp);
			
			*endereco_lista = lista;
		}
	}
}
