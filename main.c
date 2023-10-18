#include <stdio.h>
#include <stdlib.h>

#include "funcionarios.h"
#include "lista.h"

#define loop(A) int i; for(i=0; i<A; i++)

int main(){
    printf("%d\n", total);
    Funcionario A, B;
    
    preencherFuncionario(&A, "victor, 137.295.144-07, 18, 720");
    preencherFuncionario(&B, "joao, 123.567.789-10, 17, 1000");
    mostrar_funcionario(B);
    
    /*
    //Esse trecho gera buffer overflow
    Lista *empresa = NULL;
    push(empresa, "victor, 137.295.144-07, 18, 720");
    push(empresa, "joao, 333333, 17, 1000.3");
    push(empresa, "daniel, 2222, 18, 2000");
    mostrar_lista(empresa);
    */
    getch();
    
    return 0;
}

#undef loop
