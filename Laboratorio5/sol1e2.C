#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>


#define DIME 1000

using namespace std;

double boxmuller(double,double);
//Funzioni recuperate da esercizio 6 laboratorio 4...
double media(double [], int);
double varianzaC(double [], int);

int contaOutliers(double[], int, double, double, int);

int main(){

    double v[DIME];
    double med, devs;
    double estM, estDev; //Per contenere valore media e std del vettore

    cout << endl << "Inserire media e deviazione standard: ";
    cin >> med >> devs;

    if(devs <= 0){
        cout << endl << "Deviazione standard deve essere positiva! Esco!" << endl;
        return -1;
    }

    //RICORDATE: l'inizializazione del generatore di numeri casuali
    //va usata una volta sola in tutto il programma!
    srand(time(NULL));

    for(int i=0; i< DIME; i++)
        v[i]=boxmuller(med,devs);
    
    estM = media(v,DIME);
    estDev = sqrt(varianzaC(v,DIME));
   
    cout << endl <<"Media: " << estM <<"; deviazione standard: " << estDev << endl;

    for(int k=1; k<=3; k++)
        cout << endl << "\tNumero Outliers (k=" << k << "): " << contaOutliers(v,DIME,estM,estDev,k) <<  endl;
    //Ovviamente se facessimo la stessa cosa diverse volte otterremmo
    //risultati di volta in volta diversi....

    for(int j=0; j<5; j++){
        for(int i=0; i< DIME; i++)
            v[i]=boxmuller(med,devs);
    
        estM = media(v,DIME);
        estDev = sqrt(varianzaC(v,DIME));
   
        cout << endl <<"Esperimento " << j <<":";
        cout << endl << "\tMedia: " << estM <<"; deviazione standard: " << estDev << endl;
        for(int k=1; k<=3; k++)
            cout << endl << "\tNumero Outliers (k=" << k << "): " << contaOutliers(v,DIME,estM,estDev,k) <<  endl;


    }

    return 0;
}


double boxmuller(double m, double s){
    
    double u1, u2, z0;
    //Estraggo due numeri uniformemente a caso in [0,1]
    u1 = (double) rand()/RAND_MAX;
    u2 = (double) rand()/RAND_MAX;

    //Calcolo il corrispondente valore estratto da una
    //popolazione Gaussiana standard
    z0 = sqrt(-2. * log(u1))* cos(2.*M_PI*u2);

    //Restituisco il valore opportunamente trasformato
    return z0*s+m;

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


int contaOutliers(double v[], int dim, double m, double s, int ampl){

    int conta=0;
    double dist;

    for(int i=0; i< dim; i++){
        if(fabs(v[i]-m)> ampl*s) conta++;

    }
    return conta;
}

