# Compilador y opciones
CC = gcc
CFLAGS = -g

# Archivos fuente y ejecutables
SRC1 = receive.c
SRC2 = send.c
SRC3 = comunication.c
INC = ./
EXE1 = receive.out
EXE2 = send.out


all: $(EXE1) $(EXE2)


$(EXE1): $(SRC1)
	$(CC) $(CFLAGS) -o $(EXE1) $(SRC1) $(SRC3) -I $(INC)


$(EXE2): $(SRC2)
	$(CC) $(CFLAGS) -o $(EXE2) $(SRC2) $(SRC3) -I $(INC)

# Limpieza de ejecutables
clean:
	rm -f $(EXE1) $(EXE2)
