typedef struct lista Lista;

/*
void push(Lista *lista, char* ficha);
*/
void mostrar_lista(Lista* lista);

Lista * push_front(Lista *lista, char *ficha);

void exportar_csv(Lista * lista, char *nome_do_arquivo);

void importar_csv(Lista ** endereco_lista, char * nome_do_arquivo); //recebe o endereco da lista

Lista * importar_csv_retorno(Lista * lista, char * nome_do_arquivo); //a lista recebe a funcao
