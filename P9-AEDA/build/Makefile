IDIR = ../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++17 -g

ODIR=../src

.PHONY: all

_OBJ = main.o 
# _INCLUDE = lista.hpp fdAleatoria.hpp fdModulo.hpp funcionDispersion.hpp tablaHash.hpp
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: ordenacion

$(ODIR)/main.o: $(ODIR)/main.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ordenacion: $(OBJ)
	$(CC)  -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o

run: clean all
	clear
	./ordenacion