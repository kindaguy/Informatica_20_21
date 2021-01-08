#include <iostream>
#include <fstream>
//Serve per memcpy
#include <cstring>

//E fondamentale

#include "particella.h"

using namespace std;


struct myArrayPart{
	int size;
	int used;
	particella *raw;
};

#define INIT_SIZE 20

/*Anche se il nome dei parametri formali in fase dichiarativa
viene IGNORATO, puo` essere comodo metterlo per documentare il codice.
Liberissimi nella definizione di cambiare il nome dei parametri, anche se io
di solito copio-incollo le dichiarazioni nel .C come punto di partenza
per scrivere le definizioni (ma e` una cosa personale).*/

//Inizialize to empty array
int init(myArrayPart *pa);
//float init(myArrayPart *pa);
//Initialize to array of size dim
int init(myArrayPart *pa, int dim);
//Initialize reading from file (containing floats)
int init(myArrayPart *pa, const char fileName[]);

//Resize of myArray
//Parameters: 
//--pa: reference to instance to modify
//--newS: new size 
int resize(myArrayPart *pa, int newS);

//Same as resize, but with block copy (memcpy).
//Needs <cstring> != <string>
int resizeWithBlock(myArrayPart *pa, int newS);


//Initialize reading from file (containing floats)
//This time we read the file only once, and resize the 
//array when needed by doubling its current size
//We are trading space for time....
int initResize(myArrayPart *pa, const char fileName[]);


bool isFull(myArrayPart a);

//Funzioni di copia:
//Copia superficiale
int shallowCopy(myArrayPart source, myArrayPart *dest);
//Copia profonda
int deepCopy(myArrayPart source, myArrayPart *dest);

void stampaArrayPart(myArrayPart vett);
void stampaArrayPartFile(ofstream *os, myArrayPart vett);