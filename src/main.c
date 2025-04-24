#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main()
{
  int modo, dificuldade;
  char tema[20];
  char continuar;

  do
  {
    printf("--- Jogo da Forca ---\n");

    printf("Escolha o modo de jogo:\n1 - Clássico\n2 - Contra o Tempo\n> ");
    scanf("%d", &modo);

    printf("Escolha a dificuldade:\n1 - Médio\n2 - Difícil\n> ");
    scanf("%d", &dificuldade);

    printf("Escolha o tema:\n1 - Animais\n2 - Filmes\n3 - Países\n> ");
    scanf("%s", tema);

    jogar(modo, dificuldade, tema);

    printf("\nDeseja jogar novamente? (s/n): ");
    scanf(" %c", &continuar);

  } while (continuar == 's' || continuar == 'S');

  printf("\nObrigado por jogar! Até a próxima.\n");

  return 0;
}
