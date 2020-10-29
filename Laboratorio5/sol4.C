#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

#define MM 50
#define NN_BASE 100
using namespace std;

double acaso_double(double,double);

double funzione(double);

double singlemeasure(int);

double media(double [],int);

double varianzaC(double [],int);


int main(){

    int nn;

    //M=50 memorizzato come costante (vedi sopra).

    double vmisure[MM];

    double estM, estSD;

    srand(time(NULL));

    for(int k=1; k <= 5; k++){

        //Inizializzo numero di punti

        nn = k* NN_BASE;

        for(int i=0; i<MM; i++)
            vmisure[i]=singlemeasure(nn);

        estM = media(vmisure,MM);
        estSD = sqrt(varianzaC(vmisure,MM));

        cout << endl << "Numero punti: " << nn;
        cout << endl << "\tStima integrale " << estM ;
        cout << endl << "\tFluttuazioni: " << estSD;
    }
    return 0;
}


double acaso_double(double min,double max){

    double num;
    double appo;

    //Genero un numero a caso tra zero e uno in doppia precisione
    appo = (double) rand()/RAND_MAX;

    num = min+ appo * (max-min);

    return num;

}

double funzione(double x){
    return pow(x,3)*cos(x);

}


double singlemeasure(int n){

    double accu = 0;
    double x;
    //Ricordiamo:
    //-valutiamo la funzione in n punti;
    //-per ciascun punto valutiamo l'area di un
    //rettangolo di base (max-min)/n e altezza f(x).
    //Qui l'intervallo di integrazione e` [0,2]
    //Sommiamo le aree
    //ovvero, riorganizzando i termini:
    //...
    for(int i=0; i<n; i++){
        x = acaso_double(0.,2.);
        accu += funzione(x);
    }    
    //Lo scrivo in modo complicato....
    return accu*((2.-0.)/n);

}

double media(double v[], int dim){
    double accu=0;

    for(int i=0; i<dim; i++)
        accu += v[i];

    return accu/dim;

}

double varianzaC(double v[],int dim){
    double accu2=0;

    double m;

    for(int i=0; i<dim; i++)
        accu2 += v[i]*v[i];

    m=media(v,dim);

    return (accu2/dim - m*m);

}
