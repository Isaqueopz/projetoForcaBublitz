#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista_palavras.h"

#define TAM_BUFFER_LINHA 256

NoPalavra* criar_no_palavra(const char *texto_palavra) {
    NoPalavra *novo_no = (NoPalavra*) malloc(sizeof(NoPalavra));
    if (novo_no == NULL) {
        perror("Erro ao alocar memoria para novo no");
        return NULL;
    }
    novo_no->palavra = (char*) malloc(strlen(texto_palavra) + 1);
    if (novo_no->palavra == NULL) {
        perror("Erro ao alocar memoria para texto da palavra");
        free(novo_no);
        return NULL;
    }
    strcpy(novo_no->palavra, texto_palavra);
    novo_no->proximo = NULL;
    return novo_no;
}

void inserir_palavra_lista(NoPalavra **cabeca, const char *texto_palavra) {
    NoPalavra *novo_no = criar_no_palavra(texto_palavra);
    if (novo_no == NULL) {
        return;
    }
    novo_no->proximo = *cabeca;
    *cabeca = novo_no;
}

char* obter_palavra_aleatoria(NoPalavra *cabeca, int total_palavras) {
    if (cabeca == NULL || total_palavras <= 0) {
        return NULL;
    }
    int indice_aleatorio = rand() % total_palavras;
    NoPalavra *atual = cabeca;
    for (int i = 0; i < indice_aleatorio; i++) {
        if (atual == NULL || atual->proximo == NULL) {
            return cabeca->palavra;
        }
        atual = atual->proximo;
    }
    return atual->palavra;
}

void liberar_lista_palavras(NoPalavra **cabeca) {
    NoPalavra *atual = *cabeca;
    NoPalavra *proximo_no;
    while (atual != NULL) {
        proximo_no = atual->proximo;
        free(atual->palavra);
        free(atual);
        atual = proximo_no;
    }
    *cabeca = NULL;
}

int carregar_palavras_do_arquivo(const char *nome_arquivo, NoPalavra **cabeca_lista) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo de palavras");
        fprintf(stderr, "Arquivo: %s\n", nome_arquivo);
        return -1;
    }

    char buffer_linha[TAM_BUFFER_LINHA];
    int contador_palavras = 0;
    while (fgets(buffer_linha, sizeof(buffer_linha), arquivo) != NULL) {
        buffer_linha[strcspn(buffer_linha, "\n")] = 0;
        buffer_linha[strcspn(buffer_linha, "\r")] = 0;

        if (strlen(buffer_linha) > 0) {
            inserir_palavra_lista(cabeca_lista, buffer_linha);
            contador_palavras++;
        }
    }

    fclose(arquivo);
    return contador_palavras;
}
