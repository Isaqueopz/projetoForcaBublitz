#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "funcoes.h"
#include "lista_palavras.h"

#define MAX_TENTATIVAS_LEGADO 6

void desenhar_forca(int erros) {
    printf("\n");
    printf(" ___     \n");
    printf("|/  |    \n");
    printf("|   %c     \n", (erros >= 1 ? 'O' : ' '));
    printf("|  %c%c%c    \n", (erros >= 3 ? '/' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 4 ? '\\' : ' '));
    printf("|  %c %c    \n", (erros >= 5 ? '/' : ' '), (erros >= 6 ? '\\' : ' '));
    printf("|            \n");
    printf("|_         \n");
    printf("\n");
}



void jogar(int modo, int dificuldade, char *tema_id) {
    NoPalavra *lista_de_palavras = NULL;
    char nome_arquivo_tema[FILENAME_MAX];
    if (strcmp(tema_id, "1") == 0) {
    strcpy(nome_arquivo_tema,"src/animais.txt");
} else if (strcmp(tema_id, "2") == 0) {
    strcpy(nome_arquivo_tema, "src/filmes.txt");
} else if (strcmp(tema_id, "3") == 0) {
    strcpy(nome_arquivo_tema, "src/paises.txt");
} else if (strcmp(tema_id, "4") == 0) {
    strcpy(nome_arquivo_tema, "src/novelas.txt");
} else {
    printf("Tema inválido selecionado.\n");
    return;
}
    int total_palavras = carregar_palavras_do_arquivo(nome_arquivo_tema, &lista_de_palavras);

    if (total_palavras <= 0) {
        printf("Nao foi possivel carregar palavras para o tema do arquivo '%s'. Verifique o arquivo.\n", nome_arquivo_tema);
        if (lista_de_palavras != NULL) liberar_lista_palavras(&lista_de_palavras);
        return;
    }

    char *palavra = obter_palavra_aleatoria(lista_de_palavras, total_palavras);
    if (palavra == NULL) {
        printf("Nao foi possivel obter uma palavra aleatoria.\n");
        liberar_lista_palavras(&lista_de_palavras);
        return;
    }

    int tamanho = strlen(palavra);
    int tentativas = (dificuldade == 1 ? 6 : 4);
    int acertos = 0, erros = 0;
    char chute;


    int *letras_descobertas = (int*) calloc(tamanho, sizeof(int));
    if (letras_descobertas == NULL) {
        perror("Erro ao alocar memoria para letras_descobertas");
        liberar_lista_palavras(&lista_de_palavras);
        return;
    }


    time_t inicio = time(NULL);
    int tempo_limite_global = 120;
    int tempo_limite_palavra = (dificuldade == 1 ? 45 : 30);


    time_t inicio_palavra_timer = time(NULL);


    while (erros < tentativas && acertos < tamanho) {
        desenhar_forca(erros);

        printf("\nPalavra: ");
        for (int i = 0; i < tamanho; i++) {
            if (letras_descobertas[i] || palavra[i] == ' ' || palavra[i] == '-') { //
                printf("%c ", palavra[i]);
                if (!letras_descobertas[i] && (palavra[i] == ' ' || palavra[i] == '-')) {

                }
            } else {
                printf("_ ");
            }
        }
        printf("\nTentativas restantes: %d\n", tentativas - erros);


        if (modo == 2) {
            int tempo_decorrido_palavra = (int)difftime(time(NULL), inicio_palavra_timer);
            int tempo_restante_palavra = tempo_limite_palavra - tempo_decorrido_palavra;

            if (tempo_restante_palavra <= 0) {
                printf("\n⏰ Tempo esgotado para esta palavra!\n");
                erros = tentativas;
                break;
            }
            printf("⏳ Tempo restante para a palavra: %d segundos\n", tempo_restante_palavra);
        }


        printf("Digite uma letra: ");


           if (scanf(" %c", &chute) != 1) {
            int c_err;
            while ((c_err = getchar()) != '\n' && c_err != EOF);
            printf("Entrada inválida. Tente novamente.\n");
            continue;
        }



        chute = tolower(chute);

        if (!isalpha(chute)) {
            printf("Por favor, digite apenas letras.\n");
            continue;
        }

        int acertou_letra = 0;
        int ja_tentada = 0;

        for (int i = 0; i < tamanho; i++) {
            if (tolower(palavra[i]) == chute) {
                if (letras_descobertas[i]) {
                    ja_tentada = 1;
                } else {
                    letras_descobertas[i] = 1;
                    acertos++;
                    acertou_letra = 1;
                }
            }
        }

        if (ja_tentada && !acertou_letra) {
            printf("Voce ja tentou esta letra e ela estava correta!\n");
        } else if (acertou_letra) {
            printf("Bom chute!\n");
        } else {
            printf("Letra nao encontrada.\n");
            erros++;
        }
    }

    desenhar_forca(erros);

    if (acertos == tamanho) {
        printf("\n🎉 Parabens! Voce venceu! A palavra era '%s'.\n", palavra);
    } else if (erros >= tentativas && modo == 2 && (int)difftime(time(NULL), inicio_palavra_timer) >= tempo_limite_palavra) {

         printf("\n😢 Fim de jogo. A palavra era '%s'.\n", palavra);
    }
    else if (erros >= tentativas) {
         printf("\n😢 Fim de jogo. Voce foi enforcado! A palavra era '%s'.\n", palavra);
    }
    else {
        printf("\n😢 Fim de jogo. A palavra era '%s'.\n", palavra);
    }


    free(letras_descobertas);
    liberar_lista_palavras(&lista_de_palavras);
}
