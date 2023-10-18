extern int total;

typedef struct funcionario{
	char nome[30];
	char cpf[15];
	int idade;
	float salario;
}Funcionario;

#include "lista.h"

void mostrar(int num);

void preencherFuncionario(Funcionario* funcionario, char* informacoes); //vulgo string_para_funcionario

void mostrar_funcionario(Funcionario funcionario);

char* funcionario_para_string(Funcionario modelo);
