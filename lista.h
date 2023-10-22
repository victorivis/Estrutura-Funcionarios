typedef struct lista Lista;

Lista* cria_lista();

void mostrar_lista(Lista* lista);

void push_front(Lista ** endereco_lista, char *ficha);

Lista* push_front_retorno(Lista *lista, char *ficha);

void exportar_csv(Lista * lista, char *nome_do_arquivo);

void importar_csv(Lista ** endereco_lista, char * nome_do_arquivo);

Lista * importar_csv_retorno(Lista * lista, char * nome_do_arquivo);

void pop_n(Lista **endereco_lista, int destino);

char *strlwr(char string[]);

void buscar_nome(Lista *lista, char *nome);

int posicao_nome(Lista *lista, char nome[]);

//Lista* retornar_nome(Lista *lista, char nome[])
