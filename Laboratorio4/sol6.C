#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define DIM_VETT 100

using namespace std;

double acaso_double(double,double);

double media(double [], int);

double varianzaC(double [],int);

double minimo(double [], int);

double massimo(double [],int);

int main(){

    double v[DIM_VETT];

    int quanti;

    //Chiedo quanti dati e controllo valore inserito
    do{
        cout << endl << "Quanti dati vuoi inserire (<= " << DIM_VETT << "): ";
        cin >>quanti;
    }while(quanti <0 or quanti > DIM_VETT);


    //Qui sostituisto l'inserimento manuale con la generazione
    //di valori a caso tra -1 e 1 per pigrizia....

    //In questo modo, inoltre, sappiamo che
    //-il valore atteso teorico e` 0;
    //-la varianza teorica e` 1/12 * 2
    //...teorica per n grandi....e noi misuriamo la varianza
    //del campione (balla un -1 a denominatore).

    srand(time(NULL));


    for(int i=0; i<quanti; i++){
        v[i]=acaso_double(-1,1);
    }

    cout << endl;
    for(int i=0; i<quanti; i++){
        //Valori stampati su 10 caratteri ciascuno
        //una (inutile) finezza....
        //ma almeno imparate come stampare dati ben impaginati
        //per i dettagli guardare la documentazione del liguaggio

        cout << setw(10);
        cout << v[i]; 
        //Qui vado a capo ogni 5 valori
        if((i+1)%6 == 0) cout << endl;

    }
    cout << endl;


    cout << endl << "Media: " << media(v,quanti);
    cout << endl << "VarianzaCamp " << varianzaC(v,quanti);
    cout << endl << "Minimo: " << minimo(v,quanti);
    cout << endl << "Massimo: " << massimo(v,quanti);

    cout << endl;
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

double minimo(double v[], int dim){

     double m = v[0];
     
     for(int i=1; i<dim; i++)
         if(v[i]<m)
             m=v[i];

     return m;

}

double massimo(double v[],int dim){

     double m = v[0];
     
     for(int i=1; i<dim; i++)
         if(v[i]>m)
             m=v[i];

     return m;

}


