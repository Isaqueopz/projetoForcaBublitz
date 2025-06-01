CC = gcc

CFLAGS = -Wall -Wextra -Iincludes
LDFLAGS =

SRC = src/main.c src/funcoes.c src/lista_palavras.c


OBJ = $(SRC:.c=.o)


EXEC = forca


$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: clean all

all: $(EXEC)
