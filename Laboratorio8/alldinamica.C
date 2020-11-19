/*Programma che, chiesto all'utente il numero di dati interi
 *che vuole inserire, alloca un vettore della dimensione giusta
 e poi salva in un vettore di float della stessa dimensione i valori
 divisi per 3 (divisione razionale).
 Esemplifica inoltre che vettori statici e dinamici vengono (ovviamente)
 usati come sempre fatto, anche quando sono parametri di funzione.
 */


#include <iostream>

using namespace std;

//Somma gli elementi di un vettore di interi di lunghezza passata
int sommaint(int [], int);

int main(){

    int dim;

    //E` opportuno  ma non necessario inizializzare le
    //variabili puntatore a NULL. Soliti motivi di igiene

    int *vint = NULL;
    float * vfloat = NULL;

    cout << endl << "Numero dati:";
    cin >> dim;

    //Alloco dinamicamente il vettore di interi
    //della lunghezza giusta
    vint  = new int[dim];

    for(int i =0; i < dim ; i++){
        cout << endl << "Inserire dato: ";
        cin >> vint[i];
    }

    //Stampo
    cout << endl << "Vettore inserito: ";
    for(int i=0; i<dim; i++){
        cout << endl << vint[i];
    }
    cout << endl;


    cout << endl << "Somma elementi vettore: " << sommaint(vint,dim) << endl;

    //Alloco dinamicamente il vettore di float
    vfloat=new float[dim];

    for(int i=0; i< dim; i++)
        vfloat[i] = (float)vint[i]/3;


    cout << endl << "Vettore risultato ";
    for(int i=0; i<dim; i++){
        cout << endl << vfloat[i];
    }
    cout << endl;


    //Ricordiamo sempre di deallocare i vettori allocati.
    //Le seguenti due linee le ho scritte quando ho scritto la 
    //corrispondente new e poi le ho spostate...cosi` non mi sono 
    //dimenticato!

    delete [] vint;
    delete [] vfloat;
    return 0;

}

int sommaint(int v[], int dim){
    
    //Noterete che non cambia nulla rispetto a quello che abbiamo sempre fatto
    int accu=0;

    for(int i=0; i<dim; i++)
        accu += v[i];

    return accu;


}
