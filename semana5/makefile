CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

FOLDER_EXERCISES = $(patsubst %/,%,$(wildcard ex*/))
FILE_EXERCISES = $(basename $(notdir $(wildcard ex*.c)))
EXERCISES = $(FOLDER_EXERCISES) $(FILE_EXERCISES)

ENCADEADA_EXERCISES = $(basename $(shell grep -l "ex12/encadeada.h" ex*.c))
LISTA_EXERCISES = $(filter-out $(ENCADEADA_EXERCISES),$(FILE_EXERCISES))

.PHONY: all clean $(EXERCISES)

all: $(EXERCISES)

$(FOLDER_EXERCISES):
	$(CC) $(CFLAGS) $(wildcard $@/*.c) -o $@/programa.exe

$(LISTA_EXERCISES): %: %.c ex1/lista.c
	$(CC) $(CFLAGS) $^ -o $@.exe

$(ENCADEADA_EXERCISES): %: %.c ex12/encadeada.c
	$(CC) $(CFLAGS) $^ -o $@.exe

clean:
	rm -f $(foreach exercise,$(FOLDER_EXERCISES),$(exercise)/*.o $(exercise)/programa.exe) $(foreach exercise,$(FILE_EXERCISES),$(exercise).exe)
