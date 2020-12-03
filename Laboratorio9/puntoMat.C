#include "puntoMat.h"


puntoMat *caricaDaFile(const char nomefile[], int *pdim){

	puntoMat appo;
	
	int conta = 0;
	
	ifstream file_in;
	
	puntoMat *vpunti = NULL;

	//Apro stream in lettura
	file_in.open(nomefile);
	//Controllo presenza eventuali errori
	if(file_in.fail()){
		cout << endl << "Errore apertura file." << endl;
		*pdim = -1;
		return vpunti; //Che vale NULL	
	}

	//Altrimenti proseguiamo;
	//Ciclo Spoletini per conteggio

	//PRIMA LETTURA FUORI DAL CICLO
	file_in >> appo.x >> appo.y >> appo.color >> appo.carica >> appo.massa;
	
	while(!file_in.eof()){
		conta++;
		file_in >> appo.x >> appo.y >> appo.color >> appo.carica >> appo.massa;
	}

	//Resetto lo stato del file;
	//Equivalente a chiuderlo e a riaprirlo,
	//ma piu` smart...

	file_in.clear();
	file_in.seekg(0,ios::beg);

	//Registro dimensione
	*pdim = conta;

	//Preparo vettore dei punti
	vpunti = new puntoMat[conta];

	//Carico
	for(int i=0; i<conta; i++){
		file_in >> vpunti[i].x >> vpunti[i].y >> vpunti[i].color >> vpunti[i].carica >> vpunti[i].massa;
	}

	//Chiudo file
	file_in.close();

	//Restituisco indirizzo vettore in memoria
	return vpunti;
}