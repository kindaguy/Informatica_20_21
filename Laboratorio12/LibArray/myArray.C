#include "myArray.h"


//Inizialize to empty array
int init(myArrayFloat *pa){

	pa->size = 0;
	pa->used = 0;
	pa->raw = NULL;
	return 0; //Just for fun
}
//Initialize to array of size dim
int init(myArrayFloat *pa, int dim){
	
	pa->size = dim;
	pa->used = 0;
	pa->raw = new float[dim];
	
	//Compact if else
	//-1: error code for allocation issue
	return (pa->raw == NULL? -1:0); //Just for fun...

}
//Initialize reading from file (containing floats)
int init(myArrayFloat *pa, const char fileName[]){
	ifstream fileIn;

	float appo;
	int count = 0;

	fileIn.open(fileName);
	
	if(fileIn.fail()){
		return -2; //Error code for file problem.
	}

	fileIn >> appo;
	while (!fileIn.eof()){
		count++;
		fileIn >> appo;
	}

	pa->size = count;
	pa->used = 0;
	pa->raw = new float[count];

	if(pa->raw == NULL){
		fileIn.close();
		return -1;
	}
	
	fileIn.clear(); //Lowers all status flags
	fileIn.seekg(0,ios::beg); //Puts the head at the beginning of the file (i.e. rewind)
	
	for(int i=0; i<pa->size; i++){
		fileIn >> pa->raw[i];
	}
	pa->used  = count;
	
	fileIn.close();
	
	return 0;

}

//Resize of myArray
//Parameters: 
//--pa: reference to instance to modify
//--newS: new size 
int resize(myArrayFloat *pa, int newS){
	
	int top;
	//Create a new array
	float *vappo = new float[newS];
	
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
int resizeWithBlock(myArrayFloat *pa, int newS){
	
	int top;
	//Create a new array
	float *vappo = new float[newS];
	
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

	memcpy(vappo,pa->raw, top*sizeof(float));

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
int initResize(myArrayFloat *pa, const char fileName[]){
	ifstream fileIn;

	float appo;
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
	fileIn >> appo;
	while (!fileIn.eof()){
		
		//Is there space?
		if(isFull(*pa)){

			if( resize(pa, 2*pa->size) == -1) return -1;
		
		}


		//Array resized: there is space...
		pa->raw[count] = appo;
		pa->used++;
		count++;
		
		fileIn >> appo;
	}

	fileIn.close();
	
	//resize(pa,count);
	return 0;

}

bool isFull(myArrayFloat a){
	if(a.size == a.used) return true;
		else return false;
}

int shallowCopy(myArrayFloat source, myArrayFloat *dest){
	*dest = source;
	return 0;
}

//Creates another copy of the raw array in the heap as well
int deepCopy(myArrayFloat source, myArrayFloat *dest){
	float *vappo;
	
	//Exploit struct assignment to copy
	//all fields at once.
	*dest = source;

	//Overwrite original array address
	dest->raw = new float[source.size];
	
	//Sanity check
	if(dest->raw==NULL){
		return -1;
	}

	//"Block copy" (you can use for instead)
	memcpy(dest->raw,source.raw,source.used*sizeof(float));

	return 0;

}