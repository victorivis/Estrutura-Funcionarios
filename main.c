#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionarios.h"
#include "lista.h"
#include "interface.h"

#define loop(A) int i; for(i=0; i<A; i++)

int main(){
	interface();
	/*
    printf("%d\n", total);

	//Exportando
    Lista *p = NULL;
    push_front(&p, "victor, 123, 10, 80.3");
    push_front(&p, "joao, 123, 10, 80.3");
    push_back(&p, "rafael, 123, 10, 80.3");
    
    Lista *r = NULL;
    
    //pop_n(&p, 1);
    mostrar_lista(p);
    
    exportar_csv(p, "saida.txt");
    
    /*
    //Importando
    Lista *q = NULL;
    importar_csv(&q, "saida.txt");
    mostrar_lista(q);
    */
    
    return 0;
}

#undef loop
