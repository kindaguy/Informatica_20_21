/*Qui determiniamo piu` traiettorie simultaneamente*/

#include <iostream>
#include <cstdlib>
#include <ctime>

//Librerie di RooT che useremo
#include "TApplication.h" //Environment per RooT
#include "TGraph.h" //ScatterPlot
#include "TAxis.h"


#define NSTEPS 200
#define NTRAJECTORIES 100
using namespace std;


int main(){

    int dim = NSTEPS;
    int ntraj = NTRAJECTORIES;
    //Rappresentiamo ciascuna traiettoria su una riga.
    int trajectories[NTRAJECTORIES][NSTEPS];

    int times[NSTEPS];

    //Inizializziamo opportunamente il generatore di numeri casuali
    //cosi` da avere traiettorie diverse ad ogni esecuzione del codice

    srand(time(NULL));

    //Inizialmente (t=0) tutte le particelle si trovano nella posizione zero;

    for(int i=0; i<dim; i++)
        times[i]=i;


    for(int i=0; i<ntraj; i++){
        trajectories[i][0]=0;
    }


    //Ad ogni passo di tempo:
    //Estraiamo un numero a caso nell'insieme {-1,1}
    //Sommiamo la mossa alla posizione precedente
    //e la registriamo

    
    for(int k=0; k<ntraj; k++){//Traiettoria per traiettoria
    
        for(int i=1; i<dim; i++){
            trajectories[k][i] = trajectories[k][i-1]+2*(rand()%2)-1;
        }
        //Singola traiettoria generata
    }
    //Traiettorie generate!

    //Per generare 
    TApplication app("Applicazione",0,0);
    //Preparo un vettore di PUNTATORI A TGRAPH
    //Questo perche', al fine di disegnare piu` inizializzare piu` 
    //scatterplot avro` bisogno di generarli dinamicamente.

    TGraph *arrayScatter[ntraj];
    
    //Qui prepariamo gli scatterplot per ciascuna traiettoria
    for(int k=0; k<ntraj; k++){
        arrayScatter[k]=new TGraph(dim,times,trajectories[k]);
        arrayScatter[k]-> SetMarkerColor(k);
        arrayScatter[k]->SetLineColor(k);
    }
    //Qui risolviamo una rottura di scatole:
    //Le diverse traiettorie copriranno lo stesso range di ascisse
    //ma in principio (e in pratica) un diverso range in ordinata
    //Per poter vedere tutte le traiettorie per benino
    //eseguiamo il comando qui sotto, in modo "ignorante"
    
    arrayScatter[0]->SetMinimum(-40);
    arrayScatter[0]->SetMaximum(40);
    //TAxis *axis = arrayScatter[0]->GetYaxis();
    //axis->SetLimits(-40.,40.);

    //La prima traiettoria va disegnata a parte per 
    //ragioni tecniche (ve l'ho detto che RooT e` scritto da 
    //fisici!

    (*arrayScatter[0]).Draw("AC*");

    for(int k=1; k<ntraj; k++)
        (*arrayScatter[k]).Draw("C* same");


    app.Run(1);

    return 0;
}
