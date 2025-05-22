#																
#	Makefile for LAB9			
# 								
#	Author: Roko, 18.05.2025	 
#								
#								


CC = clang
LIB_PATH = ../lib
LIBS = -lLabUtils


FUNC_PATH = ./includes/c/func.c 
ZAD_PATH = ./includes/c/zad.c


OBJ = ./.tmp/*.o

all: main clean

.PHONY = main
main: func zad 
	$(CC) -L$(LIB_PATH) -Wl,-rpath=$(LIB_PATH) $(LIBS) main.c $(OBJ)  -o program

tmp:
	mkdir .tmp

func: $(FUNC_PATH) tmp	
	$(CC) -c -o ./.tmp/func.o $(FUNC_PATH) 

zad: $(ZAD_PATH) tmp
	$(CC) -c -o ./.tmp/zad.o $(ZAD_PATH)

clean:
	rm -rf .tmp