#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionarios.h"
#include "lista.h"

#define loop(A) int i; for(i=0; i<A; i++)

int main(){
    printf("%d\n", total);

	//Exportando
    Lista *p = NULL;
    p = push_front(p, "victor, 123, 10, 80.3");
    p = push_front(p, "joao, 123, 10, 80.3");
    p = push_front(p, "rafael, 123, 10, 80.3");
    
    exportar_csv(p, "saida.txt");
    
    //Importando
    Lista *q = NULL;
    importar_csv(&q, "saida.txt");
    mostrar_lista(q);
    
    return 0;
}

#undef loop
