#include <iostream>
#include "myArray.h"

using namespace std;

//Screma secondo qualche criterio:
//In ingresso il vettore, in uscita il vettore modificato.

//Il vettore modificato preserva l'ordine relativo del vettore
//originale (meno efficiente ma utile se il vettore e` strutturato,
//per esempio ordinato).
int scremaPad(myArrayFloat *pv);

//Il vettore modificato NON preserva l'ordine relativo del vettore
//originale.
int scremaSwap(myArrayFloat *pv);

int main(){

	myArrayFloat aFloat;
	int newUsed;
	init(&aFloat,"datiFloat.dat");

	cout << endl << "Vettore caricato:" << endl;
	cout << "Dimensione: " << aFloat.size << endl;
	cout << "Usati: " << aFloat.used<< endl;
	cout << "Dati: " << endl;
	for(int i=0; i<aFloat.used; i++)
		cout << aFloat.raw[i] << endl;

	//newUsed = scremaPad(&aFloat);
	newUsed = scremaSwap(&aFloat);
	
	cout << "Dopo scrematura: " ;
	for(int i=0; i<aFloat.used; i++)
		cout << aFloat.raw[i] << endl;

	return 0;
}


int scremaPad(myArrayFloat *pv){
	//Criterio: elimina tutti gli elementi >2
	//Sostituitelo con quello che serve
	for(int i=0; i<pv->used; i++){
		
		if(pv->raw[i]>2){	//Elimino elemento i-esimo
								//spostando a sx di uno tutti i successivi
			for(int j=i; j<pv->used-1; j++){
				pv->raw[j] = pv->raw[j+1];
			}
			//C'e` un elemento in meno
			pv->used--;
			//Devo ispezionare l'elemento che ora e` in posizione i;
			i--;
		}
		
	}
	//Restituisco il numero di elementi sopravvissuti
	return pv->used;
}

int scremaSwap(myArrayFloat *pv){
	//Quando incontro un elemento da eliminare lo sostituisco
	//con l'ultimo elemento valido dell'array.

	for(int i=0; i<pv->used; i++){
		
		if(pv->raw[i] >2){
			pv->raw[i] = pv->raw[pv->used-1];
			//Decremento il numero di elementi validi
			pv->used--;
			//decremento i per controllare l'elemento
			//usato come sostituto.
			i--;

		}	
	}	
	return pv->used;
}
