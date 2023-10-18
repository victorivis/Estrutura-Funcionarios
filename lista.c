#include <stdio.h>
#include <stdlib.h>

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

void push_front(Lista *lista, Funcionario modelo) {
  Lista *novo = malloc(sizeof(Lista));
  novo->funcionario = modelo;
  novo->proximo = lista;
  lista = novo;
}
