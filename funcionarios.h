extern int total;

typedef struct funcionario{
  char nome[30];
  char cpf[15];
  int idade;
  float salario;
} Funcionario;

#include "lista.h"

void mostrar(int num);

void preencherFuncionario(Funcionario* funcionario, char* informacoes); //vulgo string_para_funcionario

void mostrar_funcionario(Funcionario funcionario);

char* funcionario_para_string(Funcionario modelo);

void str2shw(char **splitado);

char ** strdvd(char string[], char separador); //retorna uma lista de strings, semelhante a funcao split() de javascript

//void limpar_funcionario(Funcionario* endereco_funcionario);
