CC = gcc
CFLAGS = -Wall -Iincludes
SRC = src/main.c src/funcoes.c
OBJ = $(SRC:.c=.o)
EXEC = forca

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(EXEC)
