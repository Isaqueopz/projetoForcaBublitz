#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "funcoes.h"

#define MAX_TENTATIVAS 6
#define TAM_MAX_PALAVRA 30

void desenhar_forca(int erros)
{
  printf("\n");
  printf(" ___     \n");
  printf("|/     |    \n");
  printf("|      %c     \n", (erros >= 1 ? 'O' : ' '));
  printf("|     %c%c%c    \n", (erros >= 3 ? '/' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 4 ? '\\' : ' '));
  printf("|     %c %c    \n", (erros >= 5 ? '/' : ' '), (erros >= 6 ? '\\' : ' '));
  printf("|            \n");
  printf("|_         \n");
  printf("\n");
}

char *escolher_palavra(char *tema, int dificuldade)
{
  static char *palavras_animais[] = {
      "gato", "cachorro", "elefante", "leao", "tigre", "zebra", "girafa", "panda", "urso", "raposa"};
  static char *palavras_filmes[] = {
      "matrix", "avatar", "titanic", "inception", "gladiador", "coraline", "jumanji", "rocky", "batman", "up"};
  static char *palavras_paises[] = {
      "brasil", "argentina", "portugal", "canada", "australia", "japao", "china", "italia", "egito", "mexico"};

  srand(time(NULL));
  int indice = rand() % 10; // Temos 10 palavras por tema

  if (strcmp(tema, "1") == 0)
    return palavras_animais[indice];
  else if (strcmp(tema, "2") == 0)
    return palavras_filmes[indice];
  else if (strcmp(tema, "3") == 0)
    return palavras_paises[indice];
  else
  {
    printf("Tema inválido.\n");
    exit(1);
  }
}

void jogar(int modo, int dificuldade, char *tema)
{
  char *palavra = escolher_palavra(tema, dificuldade);
  int tamanho = strlen(palavra);
  int tentativas = dificuldade == 1 ? 6 : 4;
  int acertos = 0, erros = 0;
  char chute;
  int letras_descobertas[TAM_MAX_PALAVRA] = {0};

  time_t inicio = time(NULL);
  int tempo_limite = 30; // segundos para o modo contra o tempo

  while (tentativas > 0 && acertos < tamanho)
  {
    if (modo == 2)
    {
      int tempo_restante = tempo_limite - (int)difftime(time(NULL), inicio);
      if (tempo_restante <= 0)
      {
        printf("\n⏰ Tempo esgotado!\n");
        break;
      }

      desenhar_forca(erros);                                        // Desenha a forca novamente antes de mostrar o tempo
      printf("\n⏳ Tempo restante: %d segundos\n", tempo_restante); // Exibe o tempo logo abaixo da forca
      fflush(stdout);                                               // Força a atualização na tela
      sleep(1);                                                     // Pausa para mostrar o tempo atualizando
    }
    else
    {
      desenhar_forca(erros); // Apenas desenha a forca no modo clássico
    }

    printf("\nPalavra: ");
    for (int i = 0; i < tamanho; i++)
    {
      if (letras_descobertas[i])
        printf("%c ", palavra[i]);
      else
        printf("_ ");
    }

    printf("\nDigite uma letra: ");
    scanf(" %c", &chute);
    chute = tolower(chute);

    int acertou = 0;
    for (int i = 0; i < tamanho; i++)
    {
      if (tolower(palavra[i]) == chute && !letras_descobertas[i])
      {
        letras_descobertas[i] = 1;
        acertos++;
        acertou = 1;
      }
    }

    if (!acertou)
    {
      tentativas--;
      erros++;
    }
  }

  desenhar_forca(erros);

  if (acertos == tamanho)
    printf("\n🎉 Parabéns! Você venceu! A palavra era '%s'.\n", palavra);
  else
    printf("\n😢 Fim de jogo. A palavra era '%s'.\n", palavra);
}
