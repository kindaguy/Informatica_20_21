#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


struct myArrayFloat{
	int size;
	int used;
	float *raw;
};

#define INIT_SIZE 20

/*Anche se il nome dei parametri formali in fase dichiarativa
viene IGNORATO, puo` essere comodo metterlo per documentare il codice.
Liberissimi nella definizione di cambiare il nome dei parametri, anche se io
di solito copio-incollo le dichiarazioni nel .C come punto di partenza
per scrivere le definizioni (ma e` una cosa personale).*/

//Inizialize to empty array
int init(myArrayFloat *pa);
//Initialize to array of size dim
int init(myArrayFloat *pa, int dim);
//Initialize reading from file (containing floats)
int init(myArrayFloat *pa, const char fileName[]);

//Resize of myArray
//Parameters: 
//--pa: reference to instance to modify
//--newS: new size 
int resize(myArrayFloat *pa, int newS);

//Same as resize, but with block copy (memcpy).
//Needs <cstring> != <string>
int resizeWithBlock(myArrayFloat *pa, int newS);


//Initialize reading from file (containing floats)
//This time we read the file only once, and resize the 
//array when needed by doubling its current size
//We are trading space for time....
int initResize(myArrayFloat *pa, const char fileName[]);


bool isFull(myArrayFloat a);

int shallowCopy(myArrayFloat source, myArrayFloat *dest);
int deepCopy(myArrayFloat source, myArrayFloat *dest);