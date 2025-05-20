CC=clang
MAIN_DEPENDS = main.c zd1 zd2 zd3 zd4
O_FILES = zad1.o zad2.o zad3.o zad4.o

all: main

main: $(MAIN_DEPENDS)
	$(CC) -L../lib -Wl,-rpath=../lib -lLabUtils -o program main.c $(O_FILES)


# Pravila za zadatke
zd1: ./includes/zad/zad1/zad1.c
	$(CC) -o zad1.o -c ./includes/zad/zad1/zad1.c

zd2: ./includes/zad/zad2/zad2.c
	$(CC) -o ./zad2.o -c ./includes/zad/zad2/zad2.c

zd3: ./includes/zad/zad3/zad3.c
	$(CC) -o ./zad3.o -c ./includes/zad/zad3/zad3.c

zd4: ./includes/zad/zad4/zad4.c
	$(CC) -o ./zad4.o -c ./includes/zad/zad4/zad4.c

clean:
	rm -f *.o