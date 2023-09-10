
project.exe : SDB.o SDBAPP.o main.o
	gcc -o project.exe SDB.o SDBAPP.o main.o

SDB.o : SDB.c
	gcc -c SDB.c

SDBAPP.o : SDBAPP.c
	gcc -c SDBAPP.c

main.o : main.c
	gcc -c main.c

clean:
	rm main.o SDB.o SDBAPP.o project.exe