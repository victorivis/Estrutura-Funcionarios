#include <stdio.h>
#include <string.h>

#include "lista.h"
#include "funcionarios.h"
#include "interface.h"

int operacao;
char nome_arquivo[] = "banco_de_funcionarios.csv"; 

void interface(){
	printf("|===================================|\n");
	printf("|                                   |\n");
	printf("|      sistema de funcionarios      |\n");
	printf("|                                   |\n");
	printf("|===================================|\n");
	printf("digite 1 para inserir funcionario\n");
	printf("digite 2 para buscar funcionario\n");
	printf("digite 3 para editar funcionario\n");
	printf("digite 4 para mostrar funcionarios\n");
	printf("digite 5 para deletar um funcionario\n");
	scanf("%d", &operacao);
	
	switch(operacao){
		case 1:
			interface_inserir();
			break;
		case 2:
			interface_buscar();
			break;
		case 3:
			interface_editar();
			break;
		case 4:
			interface_mostrar();
			break;
		case 5:
			interface_deletar();
			break;
	}
	
	printf("Digite qualquer tecla para sair ");
	getch();	
}

void interface_inserir(){
	Lista *p = cria_lista();
	char trecho[50];
	char saida[100];
	
	printf("Insira os dados do funcionarios abaixo:\n");
	
	//fflush(stdout);
	printf("Nome: ");
	scanf("%s", saida);
	strcat(saida, ", ");
	
	//fflush(stdout);
	printf("CPF: ");
	scanf("%s", trecho);
	strcat(saida, trecho);
	strcat(saida, ", ");
	
	printf("Idade: ");
	scanf("%s", trecho);
	strcat(saida, trecho);
	strcat(saida, ", ");
	
	printf("Salario: ");
	scanf("%s", trecho);
	strcat(saida, trecho);
	
	push_front(&p, saida);
	append_csv(&p, nome_arquivo);
	
	//printf("%s\n", saida);
	
	printf("Insercao foi um sucesso!\n");
	//scanf("%d", operacao);
}

void interface_deletar(){
	printf("insira o nome completo do funcionario: ");
	char nome[50];
	scanf("%s", nome);
	
	Lista *p = NULL;
	importar_csv(&p, nome_arquivo);
	
	int posicao = posicao_nome(p, nome);
	//printf("posicao = %d\n", posicao);
	if(posicao != -1){
		pop_n(&p, posicao);
		exportar_csv(p, nome_arquivo);
		printf("%s deletado com sucesso\n", nome);
	}
}

void interface_editar(){
	Lista *p = NULL;
	importar_csv(&p, nome_arquivo);
	char nome[50], saida[100], trecho[50];
	
	printf("Digite o nome completo do funcionario: ");
	scanf("%s", nome);
	
	printf("Nome: ");
	scanf("%s", saida);
	strcat(saida, ", ");
	
	printf("CPF: ");
	scanf("%s", trecho);
	strcat(saida, trecho);
	strcat(saida, ", ");
	
	printf("Idade: ");
	scanf("%s", trecho);
	strcat(saida, trecho);
	strcat(saida, ", ");
	
	printf("Salario: ");
	scanf("%s", trecho);
	strcat(saida, trecho);
	//scanf("%s", ficha_editada);
	
	
	int editar = editar_por_nome(p, nome, saida);
}

void interface_mostrar(){
	Lista *p = cria_lista();
	importar_csv(&p, nome_arquivo);
	if(p){
		printf("Nome, CPF, Idade, Salario\n");
		mostrar_lista(p);
	}
}

void interface_buscar(){
	Lista *p = NULL;
	importar_csv(&p, nome_arquivo);
	
	printf("Buscar por nome: ");
	char nome[50];
	scanf("%s", nome);
	
	buscar_nome(p, nome);
}
