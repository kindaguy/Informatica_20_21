esegui: programma.x
	./programma.x


compila: programma.x

programma.x: programma.o myArray.o
	g++ programma.o myArray.o -o programma.x


programma.o: programma.C myArray.h
	g++ -c programma.C


myArray.o: myArray.h myArray.C
	g++ -c myArray.C


