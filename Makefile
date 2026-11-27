all: exec

AVL.o: AVL.c AVL.h
	gcc -c AVL.c -o AVL.o

Age.o: Age.c Age.h
	gcc -c Age.c -o Age.o

Annee.o: Annee.c Annee.h
	gcc -c Annee.c -o Annee.o

main.o: main.c Annee.h Age.h AVL.h
	gcc -c main.c -o main.o

exec: main.o Annee.o Age.o AVL.o
	gcc main.o Annee.o Age.o AVL.o -o exec

clean:
	rm exec
	rm *.o
