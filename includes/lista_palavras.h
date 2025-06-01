#ifndef LISTA_PALAVRAS_H
#define LISTA_PALAVRAS_H

typedef struct NoPalavra {
    char *palavra;
    struct NoPalavra *proximo;
} NoPalavra;

NoPalavra* criar_no_palavra(const char *texto_palavra);
void inserir_palavra_lista(NoPalavra **cabeca, const char *texto_palavra);
char* obter_palavra_aleatoria(NoPalavra *cabeca, int total_palavras);
void liberar_lista_palavras(NoPalavra **cabeca);
int carregar_palavras_do_arquivo(const char *nome_arquivo, NoPalavra **cabeca_lista);

#endif
