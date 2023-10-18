#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionarios.h"
#include "lista.h"

#define loop(A) int i; for(i=0; i<A; i++)

int main(){
    printf("%d\n", total);
    
    /*
    Funcionario modelo, B;
    
    preencherFuncionario(&modelo, "victor, 137.295.144-07, 18, 720");
    preencherFuncionario(&B, "joao, 123.567.789-10, 17, 1000");
    
    Lista *p = NULL;
    p = push_front(p, "victor, 137.295.144-07, 18, 720");
    p = push_front(p, "joao, 123.567.789-10, 17, 1000");
    p = push_front(p, "rafael, 444.444.144-07, 18, 444");
    p = push_front(p, "daniel, 331.133.331-13, 18, 313");
	    
    mostrar_lista(p);
    */
	
	Funcionario modelo, B;
    
    preencherFuncionario(&modelo, "victor, 137.295.144-07, 18, 720");
    preencherFuncionario(&B, "joao, 123.567.789-10, 17, 1000");
    
    char* a = funcionario_para_string(modelo);
    printf("%s\n", a);
    
	getch();
    return 0;
}

#undef loop
