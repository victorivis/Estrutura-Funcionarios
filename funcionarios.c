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

char* funcionario_para_string(Funcionario modelo){
	char *saida = malloc(sizeof(char) * 100);
	sprintf(saida, "%s, %s, %d, %.2f", modelo.nome, modelo.cpf, modelo.idade, modelo.salario);
	return saida;
}

void str2shw(char **splitado){
    if(splitado[0]){
        int contador = 0;
        while(splitado[contador+1]){
            printf("%s,", splitado[contador++]);
        }
        if(splitado[contador]){
            printf("%s\n", splitado[contador]);
        }
    }
}

char ** strdvd(char string[], char separador){
    int inicio=0, fim=0, contador=0;
    char **saida = malloc(sizeof(char *));
    int length = strlen(string);
    do{
        if(string[fim] == separador || string[fim] == '\0'){ //tenta copiar o trecho se chegar no separador ou no fim da string
            int tamanho = fim-inicio;
            if(tamanho){//No caso se existir algo entre os separadores
                char *trecho = malloc(sizeof(char) * (tamanho+1));
                strncpy(trecho, string + inicio, tamanho);
                trecho[tamanho] = '\0';
                
                saida[contador++] = trecho; //Colocando a string na lista de strings
                saida = realloc(saida, sizeof(char *) * (contador+1)); //criando um espaço extra na lista de strings
            } else{//Caso tenha dois separadores seguidos ele cria uma string com um texto ja definido
                char *trecho = malloc(sizeof(char)*2);
                trecho[0] = (char) 6;
                trecho[1] = '\0';
                
                saida[contador++] = trecho;
                saida = realloc(saida, sizeof(char *) * (contador+1));
            }
            
            inicio = fim+1; //reajusta o comeco da proxima string
        }
        fim++;
    }while(string[fim-1]);
    
    saida[contador] = NULL;
    return saida;
}

/*
//ainda nao funcional
char* str2mrg(char **splitado, char juntador){
    int contador = 0, atual = 0;
    if(splitado[0]){
        char *saida = malloc(sizeof(char*) * (strlen(splitado[0])+1) );
        while(splitado[contador+1]){
            sprintf(saida, "%s%c", splitado[contador++], juntador);
            
            int tamanho_atual = strlen(saida);
            atual+= tamanho_atual+1;
            
            saida = realloc(saida, (size_t) (tamanho_atual + strlen(splitado[contador])) );
        }
        if(splitado[contador]){
            printf("%s\n", splitado[contador]);
        }
    }
}
*/

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

/*
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
*/

void preencherFuncionario(Funcionario* modelo, char* informacoes){
  char ficha[strlen(informacoes)+5];
  strcpy(ficha, informacoes);

  char **lista_strings = strdvd(informacoes, ',');

  int contador = 0;

  if(lista_strings[contador]) strcpy(modelo->nome, lista_strings[contador++]);
  if(lista_strings[contador]){
    if(lista_strings[contador][0] == ' ') strcpy(modelo->cpf, &(lista_strings[contador++][1]) );
    else strcpy(modelo->cpf, lista_strings[contador++]);
  }
  if(lista_strings[contador]) modelo->idade = atoi(lista_strings[contador++]);
  if(lista_strings[contador]) modelo->salario = atof(lista_strings[contador++]);
  
  while(contador--){
  	free(lista_strings[contador]);
  }
  free(lista_strings);
}

void mostrar_funcionario(Funcionario funcionario){
  printf("%s, ", funcionario.nome);
  printf("%s, ", funcionario.cpf);
  printf("%d, ", funcionario.idade);
  printf("%.2f\n", funcionario.salario);
}

