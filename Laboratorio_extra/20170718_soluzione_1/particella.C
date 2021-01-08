#include "particella.h"

bool isout(particella part){
	if(fabs(part.x)>RECT_MAX_X or fabs(part.y)> RECT_MAX_Y)
		return true;
		
	else
		return false; 
}

void swapPart(particella *p1, particella *p2){
	particella appo;
	appo = *p1;
	*p1 = *p2;
	*p2 = appo;
}

void stampaPart(particella part){
	cout << setw(10) << part.x << setw(10) << part.y << setw(10) << part.vx << setw(10) << part.vy << endl;
}

void stampaPartFile(ofstream *os, particella part){
	(*os) <<setw(10)<< part.x << setw(10) << part.y <<setw(10)<< part.vx << setw(10)<< part.vy << endl;
}

//Specializzazione lettura (da file) per particella
void leggiPartFile(ifstream *is, particella * pPart){
	(*is)  >> pPart->x >> pPart->y >> pPart->vx >> pPart->vy;
}


void evolvi(particella *pPart, float dt){
	pPart->x += pPart->vx*dt;
	pPart->y += pPart->vy*dt;
}