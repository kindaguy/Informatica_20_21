#include <iostream>
#include <fstream>
#include "myArrayPart.h"

//RooT
#include "TApplication.h"
#include "TGraph.h"



#define DELTAT 1.5f


using namespace std;

int scremaParticelle(myArrayPart *pVett, ofstream *os);

int main(){

    int error = 0;
    int npartT0;
    int npartT1;
    int npartOutT0;
    int npartOutT1;

    myArrayPart vettore;
    ofstream fileOut;
    
    //Prepariamo per file risultati
    fileOut.open("risultati.dat");

    //Punto 1
    error = initResize(&vettore,"particelle.dat");

    if(error == 0){
        cout << "Vettore caricato!" << endl;
        cout << "Particelle caricate: " << vettore.used << endl;
        cout << "Descrizione particelle caricate:" << endl;
        stampaArrayPart(vettore);
        //Stampa su file
        fileOut << "Vettore caricato!" << endl;
        fileOut << "Particelle caricate: " << vettore.used << endl;
        fileOut << "Descrizione particelle caricate:" << endl;
        stampaArrayPartFile(&fileOut, vettore);
    }
    else{
        cout << endl << "Errore. Il codice di errore e`" << error << endl;
        return error;
    }
    
    //Punto 2:prima scrematura
    npartT0 = vettore.used;
    
    npartOutT0 = scremaParticelle(&vettore,&fileOut);
    
    cout << endl << "Al tempo t0=0 le particelle eliminate sono: " << npartOutT0 << endl; 

    cout << endl << "Le particelle interne al tempo t0 sono " << vettore.used << endl;
    //Su file
    fileOut << endl << "Al tempo t0=0 le particelle eliminate sono: " << npartOutT0 << endl; 
    fileOut << endl << "Le particelle interne al tempo t0 sono " << vettore.used << endl;
    
    
    //Punto 3: evoluzione
    for(int i = 0; i<vettore.used; i++)
        evolvi(&(vettore.raw[i]),DELTAT);

    //Punto 4
    npartOutT1 = scremaParticelle(&vettore,&fileOut);
    cout << endl << "Al tempo t1=1.5 le particelle eliminate sono: " << npartOutT1 << endl; 
    cout << endl << "Le particelle interne al tempo t1 sono " << vettore.used << endl;
    
    //File
    fileOut << endl << "Al tempo t1=1.5 le particelle eliminate sono: " << npartOutT1 << endl; 
    fileOut << endl << "Le particelle interne al tempo t1 sono " << vettore.used << endl;
    
    fileOut.close();

    //RooT
    float * vettx, *vetty;
    vettx = new float[vettore.used];
    vetty = new float[vettore.used];
    for(int i=0; i<vettore.used; i++){
        vettx[i] = vettore.raw[i].x;
        vetty[i] = vettore.raw[i].y;
    }
    TApplication app("Applicazione",0,0);
    TGraph scatter(vettore.used,vettx,vetty);
    scatter.Draw("A*");
    app.Run(0);
    
    delete [] vettx;
    delete [] vetty;
    delete [] vettore;

    return error;
}


 int scremaParticelle(myArrayPart *pVett, ofstream *os){
 	int contaOut = 0;
 	particella *appov;
 	//Da qui in avanti posso usare appov in modo agile per accedere al vettore
 	appov = pVett->raw;
 	cout << endl <<"Procedo con scrematura: " << endl;
 	cout << endl <<"Descrizione particelle eliminate: ";
 	cout << endl << setw(10) << "x"<< setw(10) << "y"<< setw(10) << "vx"<< setw(10) << "vy" << endl;
    //File
    (*os)<< endl <<"Procedo con scrematura: " << endl;
 	(*os)<< endl <<"Descrizione particelle eliminate: ";
 	(*os)<< endl << setw(10) << "x"<< setw(10) << "y"<< setw(10) << "vx"<< setw(10) << "vy" << endl;
 	for(int i=0; i<pVett->used; i++){
 		if(isout(appov[i])){
 			stampaPart(appov[i]);
            stampaPartFile(os,appov[i]);
 			contaOut++;
 			swapPart(appov+i, appov+pVett->used-1);
 			pVett->used--;
 			//Devo ispezionare l'elemento appena spostato
 			i--;
 		}
 	}

    //Terminata scrematura. Resize? Facoltativo...

 	return contaOut;

 }


