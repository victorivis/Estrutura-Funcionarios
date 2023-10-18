extern int total;

typedef struct funcionario{
	char nome[30];
	char cpf[15];
	int idade;
	float salario;
}Funcionario;

#include "lista.h"

void mostrar(int num);

void preencherFuncionario(Funcionario* funcionario, char* informacoes);

void mostrar_funcionario(Funcionario funcionario);
