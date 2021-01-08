CFLAGS=`root-config --cflags`
LIBS=`root-config --libs` 

esegui: compila
	./soluzione.x

compila: soluzione.x

soluzione.x: soluzione.o myArrayPart.o particella.o
	g++ soluzione.o myArrayPart.o particella.o -o soluzione.x $(LIBS)

particella.o: particella.C particella.h
	g++ -c particella.C

myArrayPart.o: myArrayPart.C myArrayPart.h
	g++ -c myArrayPart.C

soluzione.o: soluzione.C particella.h myArrayPart.h
	g++ -c soluzione.C $(CFLAGS)