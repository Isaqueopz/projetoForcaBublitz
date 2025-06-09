#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoes.h"

int main() {
    srand(time(NULL));

    int modo, dificuldade;
    char tema_id[2];
    char continuar;

    do {
        printf("--- Jogo da Forca ---\n");

        do {
            printf("Escolha o modo de jogo:\n1 - Classico\n2 - Contra o Tempo\n> ");
            if (scanf("%d", &modo) != 1 || (modo != 1 && modo != 2)) {
                printf("Opcao invalida. Tente novamente.\n");

                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                modo = 0;
            } else {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                break;
            }
        } while (1);


        do {
            printf("Escolha a dificuldade:\n1 - Normal (6 erros)\n2 - Dificil (4 erros)\n> ");
            if (scanf("%d", &dificuldade) != 1 || (dificuldade != 1 && dificuldade != 2)) {
                printf("Opcao invalida. Tente novamente.\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                dificuldade = 0;
            } else {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                break;
            }
        } while (1);

  do {
    printf("Escolha o tema:\n1 - Animais\n2 - Filmes\n3 - Paises\n4 - Novelas\n> ");
    if (scanf("%1s", tema_id) != 1 ||
        (strcmp(tema_id,"1") != 0 && strcmp(tema_id,"2") != 0 &&
         strcmp(tema_id,"3") != 0 && strcmp(tema_id,"4") != 0)) {
        printf("Opcao invalida. Tente novamente.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        strcpy(tema_id, "0");
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        break;
    }
} while(1);



        jogar(modo, dificuldade, tema_id);


        do {
            printf("\nDeseja jogar novamente? (s/n): ");
            if (scanf(" %c", &continuar) != 1) {
                 printf("Entrada invalida.\n");
                 int c;
                 while ((c = getchar()) != '\n' && c != EOF);
                 continuar = ' ';
            } else {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                if (tolower(continuar) == 's' || tolower(continuar) == 'n') {
                    break;
                } else {
                    printf("Entrada invalida. Digite 's' ou 'n'.\n");
                    continuar = ' ';
                }
            }
        } while(1);


    } while (tolower(continuar) == 's');

    printf("\nObrigado por jogar! Ate a proxima.\n");

    return 0;
}
