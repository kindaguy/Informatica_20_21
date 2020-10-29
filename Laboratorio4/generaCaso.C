//#include copia e incolla tutte le dichiarazioni di funzione contenute in un file che si chiama
// iostream.h che si trova da qualche parte sul vostro computer

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
//Dichiarazione di costante DIM 

#define DIM 20




//Da questo punto in avanti il compilatore operera` una sostituzione
//lessicografica di ogni occorrenza della sequenza di caratteri DIM 
//con la sequenza di caratteri 10
//Comodo: se vorremo cambiare la dimensione del vettore, e tutti i 
//costrutti che la usano, dovremo modificare il codice in un solo 
//punto!

int main(){

    int v[DIM];
    int max;


    //Imposta il seme del generatore di numeri casuali
    //usando l'orologio di sistema
    //Questo consente di avere sequenze di numeri diversi in diverse 
    //esecuzioni del programma.

    srand(time(NULL));

    //Attenzione: va chiamato una sola volta all'interno dell'intero programma!

    cout << endl << "RAND_MAX = " << RAND_MAX << endl;
    //Carico
    for(int i = 0 ; i < DIM ; i++)
        v[i] = rand();

    //Stampo

    cout << endl << "Vettore generato: ";

    for(int i=0; i < DIM; i++)
        cout  << endl << "v[" << i << "]= " << v[i];

    cout << endl;

    do{
    
        cout << endl << "Inserire valore massimo da generare (>0): ";
        cin >> max;
    }while(max <=0);

    cout << endl << "Valori modulo max+1: ";

    for(int i=0; i < DIM; i++)
        cout  << endl << "v[" << i << "]= " << v[i]%(max+1);

    cout << endl;



    return 0;

}
    

