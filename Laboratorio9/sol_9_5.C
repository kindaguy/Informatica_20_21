#include <iostream>
#include <iomanip>

#include "puntoMat.h"

//Includes di RooT
#include "TApplication.h"
#include "TGraph.h"

using namespace std;


int main(){

	puntoMat * v;
	int dim;

	//Delego ad una funzione il caricamento.
	v = caricaDaFile("puntiPiano.dat",&dim);

	//Controllo che non ci siano stati problemi
	if(v == NULL){
		cout << endl << "Errore in fase di caricamento....esco" << endl;
	}

	
	cout << endl <<  setw(10)<<  "x" << setw(10) << "y"<< setw(10)<< "col" << setw(10) << "car" << setw(10) << "mass" << endl;
	for(int i =0; i < dim; i++){
		cout << endl << setw(10) << v[i].x  << setw(10)<< v[i].y << setw(10)<< v[i].color << setw(10)<< v[i].carica << setw(10)<< v[i].massa;
	}
	cout << endl;

	/*******************/
	/*Sezione Root*/
	/*******************/

	double *vx = new double[dim];
	double *vy = new double[dim];

	//Carico il vettore delle ascisse e delle ordinate
	for(int i=0; i<dim; i++){
		vx[i] = v[i].x;
		vy[i] = v[i].y;
	}

	TApplication app("Pippo",0,0);

	TGraph scat(dim, vx, vy);

	scat.Draw("A*");

	app.Run(0);

	delete [] vx;
	delete [] vy;
	delete [] v;

	return 0;
}