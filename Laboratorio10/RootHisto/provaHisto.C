#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>

//Librerie ROOT
#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"

//Costanti
#define NN 100
#define PI 3.1415f

using namespace std;



int main(){

    float errori[NN];
    float appo1,appo2;

    float mean = 0.f;
    float stdDev = 0.4f;

    float scotts;
    int nbins;

    float min, max;

    //srand(time(NULL));

    for(int i=0; i<NN; i+=2){
        appo1 = ((double)rand())/RAND_MAX;
        appo2 = ((double)rand())/RAND_MAX;
        errori[i] = stdDev*(sqrt(-2*log(appo1))*cos(2*PI*appo2))+mean;
        errori[i+1] = stdDev*(sqrt(-2*log(appo1))*sin(2*PI*appo2))+mean;
        cout << endl << "Err1 : " << errori[i] << " Err2: " << errori[i+1] << endl;
    }

    //Calcolo minimo e massimo

    min = errori[0];
    max  = errori[0];
    for(int i=0; i<NN; i++){
    if(errori[i] < min)
        min = errori[i];
    if(errori[i]>max)
        max = errori[i];
    }

    cout << endl << "Valore minimo: " << min;
    cout << endl << "Valore massimo: " << max;



    scotts = 3.5f * stdDev / pow((float)NN,1.f/3.f);
    nbins = ceil((max - min)/scotts);
    //nbins=10;
    cout << endl << "Numero bins (determinato con Scotts): " << nbins << endl;

    //Suppongo stdDev dei dati essere uguale a quella nota. Non e` vero, ma cambia poco.

    //Creazione ecosistema
    TApplication *app = new TApplication("Applicazione",0,0);
    
    //Creazione istogramma
    //Parametri (in ordine di apparizione):
    //Nome interno root
    //Nome finestra
    //numero bins
    //inizio intervallo
    //fine intervallo
    TH1F * histogram = new TH1F("Histo","Error Histogram", nbins, min-1e-3,max+1e-3);

    //Riempio istogramma (ci pensa root a cestinare nel modo giusto)

    for(int i=0; i<NN; i++)
        histogram ->Fill(errori[i]);

    histogram ->Draw();

    
    app->Run(1);



    return 0;


}
