#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int CAMPOS_FUNCIONARIO=4;
int total = 15;

typedef struct funcionario{
  char nome[30];
  char cpf[15];
  int idade;
  float salario;
} Funcionario;

void mostrar(int num){
  printf("%d\n", num);
}

void * percorrerFuncionario(Funcionario *funcionario, int num){
  switch(num){
    case 0:
      return funcionario->nome;
    case 1:
      return funcionario->cpf;
    case 2:
      return &(funcionario->idade);
    case 3:
      return &(funcionario->salario);
  }
}


void preencherFuncionario(Funcionario* modelo, char* informacoes){
  char ficha[strlen(informacoes)+5];
  strcpy(ficha, informacoes);
  char *token = strtok(ficha, ",");

  if(token) strcpy(modelo->nome, token);

  if(token) token = strtok(NULL, ",");
  if(token) strcpy(modelo->cpf, token);

  if(token) token = strtok(NULL, ",");
  if(token) modelo->idade = atoi(token);

  if(token) token = strtok(NULL, ",");
  if(token) modelo->salario = atof(token);
}

void mostrar_funcionario(Funcionario funcionario){
  printf("%s, ", funcionario.nome);
  printf("%s, ", funcionario.cpf);
  printf("%d, ", funcionario.idade);
  printf("%.2f\n", funcionario.salario);
}
