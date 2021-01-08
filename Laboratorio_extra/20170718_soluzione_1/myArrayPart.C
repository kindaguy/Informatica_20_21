#include "myArrayPart.h"


//Inizialize to empty array
int init(myArrayPart *pa){

	pa->size = 0;
	pa->used = 0;
	pa->raw = NULL;
	return 0; //Just for fun
}
//Initialize to array of size dim
int init(myArrayPart *pa, int dim){
	
	pa->size = dim;
	pa->used = 0;
	pa->raw = new particella[dim];
	
	//Compact if else
	//-1: error code for allocation issue
	return (pa->raw == NULL? -1:0); //Just for fun...

}
//Initialize reading from file (containing floats)
int init(myArrayPart *pa, const char fileName[]){
	ifstream fileIn;

	particella appo;
	int count = 0;

	fileIn.open(fileName);
	
	if(fileIn.fail()){
		return -2; //Error code for file problem.
	}
	//Osservazione: potremmo fare overloading di >> per specializzarlo
	//a leggere particelle, ma evitiamo...
	//fileIn >> appo.x >> appo.y >> appo.vx >> appo.vy;
	//Sostituiamo con
	leggiPartFile(&fileIn,&appo);
	while (!fileIn.eof()){
		count++;
		leggiPartFile(&fileIn,&appo);
	}

	pa->size = count;
	pa->used = 0;
	pa->raw = new particella[count];

	if(pa->raw == NULL){
		fileIn.close();
		return -1;
	}
	
	fileIn.clear(); //Lowers all status flags
	fileIn.seekg(0,ios::beg); //Puts the head at the beginning of the file (i.e. rewind)
	
	for(int i=0; i<pa->size; i++){
		leggiPartFile(&fileIn,&(pa->raw[i]));
		//fileIn >> pa->raw[i];
	}
	pa->used  = count;
	
	fileIn.close();
	
	return 0;

}

//Resize of myArray
//Parameters: 
//--pa: reference to instance to modify
//--newS: new size 
int resize(myArrayPart *pa, int newS){
	
	int top;
	//Create a new array
	particella *vappo = new particella[newS];
	
	if(vappo == NULL){
		return -1;
	}

	//Check the upper index
	top = (newS >= pa->size?pa->size:newS);

	for(int i=0; i<top; i++){
		vappo[i]=pa->raw[i];
	}

	//Update size
	pa->size = newS;
	//Update used;
	pa->used = top;
	//Detele the old array in heap
	delete [] pa->raw;
	//point to the new array
	pa->raw = vappo;
	
	return 0;



}

//Resize of myArray
//Parameters: 
//--pa: reference to instance to modify
//--newS: new size 
int resizeWithBlock(myArrayPart *pa, int newS){
	
	int top;
	//Create a new array
	particella *vappo = new particella[newS];
	
	if(vappo == NULL){
		return -1;
	}

	//Check the upper index
	top = (newS >= pa->size?pa->size:newS);
	
	//Pay attention here
	//Copies a block of top*sizeof(float) bytes
	//starting from the memory address pa->raw (source) to the
	//to a block of memory of the same size starting
	//at vappo (destination)

	memcpy(vappo,pa->raw, top*sizeof(particella));

	//Smart!


	//Update size
	pa->size = newS;
	//Update used;
	pa->used = top;
	//Detele the old array in heap
	delete [] pa->raw;
	//point to the new array
	pa->raw = vappo;
	
	return 0;
	
}





//Initialize reading from file (containing floats)
//This time we read the file only once, and resize the 
//array when needed by doubling its current size
//We are trading space for time....
int initResize(myArrayPart *pa, const char fileName[]){
	ifstream fileIn;

	particella appo;
	int count = 0;

	fileIn.open(fileName);
	
	if(fileIn.fail()){
		return -2; //Error code for file problem.
	}

	//Initial allocation of the array
	

	if(init(pa,INIT_SIZE) == -1){
		fileIn.close();
		return -1; //Memory allocation error
	}
	
	//Ho un vettore di dimensione INIT_SIZE a disposizione
	leggiPartFile(&fileIn,&appo);
	//fileIn >> appo;
	while (!fileIn.eof()){
		
		//Is there space?
		if(isFull(*pa)){

			if( resize(pa, 2*pa->size) == -1) return -1;
		
		}


		//Array resized: there is space...
		pa->raw[count] = appo;
		pa->used++;
		count++;
		
		leggiPartFile(&fileIn,&appo);
	}

	fileIn.close();
	
	//resize(pa,count);
	return 0;

}

bool isFull(myArrayPart a){
	if(a.size == a.used) return true;
		else return false;
}

int shallowCopy(myArrayPart source, myArrayPart *dest){
	*dest = source;
	return 0;
}

//Creates another copy of the raw array in the heap as well
int deepCopy(myArrayPart source, myArrayPart *dest){
	particella *vappo;
	
	//Exploit struct assignment to copy
	//all fields at once.
	*dest = source;

	//Overwrite original array address
	dest->raw = new particella[source.size];
	
	//Sanity check
	if(dest->raw==NULL){
		return -1;
	}

	//"Block copy" (you can use for instead)
	memcpy(dest->raw,source.raw,source.used*sizeof(particella));

	return 0;

}


void stampaArrayPart(myArrayPart vett){
 cout << setw(10) << "x" << setw(10) << "y" << setw(10) << "vx" << setw(10) << "vy"<< endl; 
   for(int i=0; i<vett.used; i++){
		stampaPart(vett.raw[i]);
	}
}

void stampaArrayPartFile(ofstream *os, myArrayPart vett){
 (*os) << setw(10) << "x" << setw(10) << "y" << setw(10) << "vx" << setw(10) << "vy"<< endl; 
   for(int i=0; i<vett.used; i++){
		stampaPartFile(os,vett.raw[i]);
	}
}