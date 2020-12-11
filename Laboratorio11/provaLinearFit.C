#include <iostream>
#include <cstdlib>
#include <ctime>

//Librerie root
#include "TCanvas.h" //Tele su cui disegnare
#include "TApplication.h" //Runtime environment
#include "TGraph.h" //ScatterPlot
#include "TH1F.h" //Istogrammi
#include "TF1.h" //Funzioni a una variabile
#include "TEllipse.h"

using namespace std;

//Un commento
int main(int argc, char ** argv){

    float * vett_x;
    float * vett_y;

    TApplication app("Applicazione",&argc /* 0 */, argv /* 0 */);

    const int dim = 10;
    float discr = 20;
    vett_x = new float[dim];
    vett_y = new float[dim];


    for(int i=0; i<dim; i++){
        vett_x[i] = i;
        vett_y[i] = 1.2 + 3*vett_x[i]+ 2 * vett_x[i] + ((float) rand() /RAND_MAX)*discr-1;
        cout << endl << vett_y[i];

    }


    TGraph * grafo = new TGraph(dim,vett_x,vett_y);
    grafo->Draw("A*");
    grafo->Fit("pol1");

    TF1 * funzione  = grafo->GetFunction("pol1");
    //TF1 *funzione = new TF1("funzione1","sin(10*x)+x",-1,1);
    //funzione -> SetLineColor(3);

    cout << endl << "I parametri di fit con curva p[0] +  p[1]*x  sono: " << endl;
    cout << "p[0] = " << funzione->GetParameter(0) << endl;
    cout << "p[1] = " << funzione->GetParameter(1) << endl;

    //funzione ->Draw("same");
       app.Run(1);



    return 0;
}
