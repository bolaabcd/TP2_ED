#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa ordena
# Autor		: Artur Gaspar da Silva (artur.gaspar@dcc.ufmg.br)
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

# Diretórios
INCLUDE_FOLDER = ./include/
BIN_FOLDER = ./bin/
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/

# Opções do compilador
CC = g++
CFLAGS = -Wall -c -I$(INCLUDE_FOLDER)
LIBS = -lm

# Arquivos
TARGET = $(BIN_FOLDER)/ordena
HDR_FILES = $(INCLUDE_FOLDER)/heap_string.hpp $(INCLUDE_FOLDER)/heapsort_recursivo.hpp $(INCLUDE_FOLDER)/memlog.hpp $(INCLUDE_FOLDER)/mergesort_nao_recursivo.hpp $(INCLUDE_FOLDER)/mergesort_recursivo.hpp $(INCLUDE_FOLDER)/msgassert.hpp $(INCLUDE_FOLDER)/ordenador.hpp $(INCLUDE_FOLDER)/quicksort_nao_recursivo.hpp $(INCLUDE_FOLDER)/rodada_intercalator.hpp $(INCLUDE_FOLDER)/rodada_manipulator.hpp $(INCLUDE_FOLDER)/url_acessos.hpp
OBJ_FILES = $(OBJ_FOLDER)/ordena.o $(OBJ_FOLDER)/heap_string.o $(OBJ_FOLDER)/heapsort_recursivo.o $(OBJ_FOLDER)/memlog.o $(OBJ_FOLDER)/mergesort_nao_recursivo.o $(OBJ_FOLDER)/mergesort_recursivo.o $(OBJ_FOLDER)/ordenador.o $(OBJ_FOLDER)/quicksort_nao_recursivo.o $(OBJ_FOLDER)/rodada_intercalator.o $(OBJ_FOLDER)/rodada_manipulator.o $(OBJ_FOLDER)/url_acessos.o

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) -o $(TARGET) $(LIBS) $(OBJ_FILES)

$(OBJ_FOLDER)/memlog.o: $(HDR_FILES) $(SRC_FOLDER)/memlog.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/memlog.o $(SRC_FOLDER)/memlog.cpp

$(OBJ_FOLDER)/ordena.o: $(HDR_FILES) $(SRC_FOLDER)/ordena.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/ordena.o $(SRC_FOLDER)/ordena.cpp

$(OBJ_FOLDER)/rodada_manipulator.o: $(HDR_FILES) $(SRC_FOLDER)/rodada_manipulator.cpp
	$(CC) $(CFLAGS) -o $(OBJ_FOLDER)/rodada_manipulator.o $(SRC_FOLDER)/rodada_manipulator.cpp 

clean:
	rm $(TARGET) $(OBJ_FILES) 
