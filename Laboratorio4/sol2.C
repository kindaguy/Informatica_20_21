#include <iostream>

#define DIME 20
using namespace std;


int main(){

    int v[DIME];
    int quanti;
    int contaneg = 0;

    do{
        cout << endl << "Quanti valori: (<= " << DIME <<"!):";
        cin >> quanti;
    }while(quanti>DIME or quanti<0);

    for(int i=0; i<quanti; i++){
        cout << endl << "Inserire valore ("<< i+1 << " di " << quanti <<"): ";
        cin >> v[i];
        //Conto negativi mentre utente inserisce
        if(v[i]<0) contaneg++;

    }


    cout << endl << "Numero negativi: " << contaneg << endl;
    
    //Facciamo pulizia.
    //quanti terra` sempre traccia dei dati "buoni presenti"
    
    for(int i=0; i<quanti; i++){
        //Ciclo piu` esterno, che mi dice che devo controllare tutto il vettore
        if(v[i]<0){ //Se l'elemento che sto ispezionando e` da buttare
            for(int j=i; j<quanti-1; j++){
                //Traslo di una posizione a sx tutti gli elementi 
                //dall'i+1-esimo in avanti. Attenzione ai valori
                //estremali dell'indice j
                v[j]=v[j+1];
            }
            //Finito shift a sx dei dati.
            //Ma non e` finita;
            quanti--; //Adesso i dati sono uno di meno
            //Devo ricordarmi di controllare
            //il valore che ho appena sovrascritto
            //a quello cattivo: potrebbe essere a
            //sua volta cattivo! Quindi....
            i--;    
        }
        //Atrimimenti non faccio nulla.
    }

    cout << endl << "Sopravvissuti " << quanti << " elementi" << endl; 
    //Stampa finale, non imbellettata...ma non importa!
    for(int i=0; i<quanti; i++)
        cout << endl << v[i];

    cout << endl;

    return 0;
}
