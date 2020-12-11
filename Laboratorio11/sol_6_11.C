#include <iostream>
#include <fstream>
#include <string>

//Include di RooT
#include "TApplication.h"
#include "TGraph.h"
#include "TF1.h"

using namespace std;

int main(){

	int conta = 0;
	ifstream filein;
	string appo;
	
	float *xc;
	float *yc;

	filein.open("datiMoto.dat");
	if(filein.fail()){
		cout << endl << "Problema esco." << endl;
		return -1;
	}

	getline(filein,appo);
	while(!filein.eof()){
		conta++;
		getline(filein,appo);	
	}

	filein.close();
	
	cout << endl << "Il numero di dati letti e`: " << conta << endl;
	filein.open("datiMoto.dat");	

	xc = new float[conta];
	yc = new float[conta];

	for(int i=0; i<conta; i++)
		filein >> xc[i] >> yc[i];


	TApplication app("Applicazione",0,0);
	TGraph scat(conta, xc, yc);

	scat.Draw("A*");

	//Chiedo allo scatterplot di fare un Fit usando un 
	//polinomio di primo grado
   scat.Fit("pol1");

   TF1 *funzione  = new TF1("regressione","[0]+[1]*x",0,90);
   
   //funzione -> SetLineColor(4);

	funzione -> SetParameter(0,1.2);
	funzione -> SetParameter(1,0.2);
	
	cout << endl << "I parametri di fit con curva p[0] +  p[1]*x  sono: " << endl;
   cout << "p[0] = " << funzione->GetParameter(0) << endl;
   cout << "p[1] = " << funzione->GetParameter(1) << endl;
	funzione -> SetLineColor(4);
	funzione->Draw("same");
	app.Run();

	return 0;
}