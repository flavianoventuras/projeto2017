CC=gcc
CFLAGS=-I. -Wall
DEPS = types.h
OBJ = main.o arquivos.o funcionarios.o clientes.o


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


bdmercado: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)