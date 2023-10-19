typedef struct lista Lista;

/*
void push(Lista *lista, char* ficha);
*/
void mostrar_lista(Lista* lista);

Lista * push_front(Lista *lista, char *ficha);

void exportar_csv(Lista * lista, char *nome_do_arquivo);
