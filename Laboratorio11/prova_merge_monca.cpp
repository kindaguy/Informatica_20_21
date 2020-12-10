#include <iostream>
#include <cstdlib>
#include <ctime>

#define SIZE 20

using namespace std;


/*Dichiarazione di funzioni*/
void stampa(int *, int);
void mergesort(int *, int, int);
void merge(int *, int, int, int);


/*Programma*/

int main() {
    cout << "Programma di ordinamento con mergesort" <<endl;

    int vett[SIZE];

    int dim = SIZE;

    srand(time(NULL)); //Inizializzo il generatore di numeri casuali

    for(int i=0; i<dim; i++)
        vett[i]= rand()% 20;

    cout << endl;

    cout << endl << "Vettore generato:";
    stampa(vett,dim);

    mergesort(vett,0, dim-1);


    cout << endl << "Vettore ordinato";
    stampa(vett,dim);


    return 0;
}


/*Definizione delle funzioni */

void stampa(int *v, int dim){
    cout << endl << "Stampo vettore: " <<  endl;

    for(int i=0; i<dim; i++)
        cout << endl << v[i];
    cout << endl;


}

void mergesort(int *v, int low, int high){
    //Riempire
  }

void merge(int *v, int low, int mid, int high) {

    int i, h, j;
    int size; //Non necessaria, la metto per chiarezza

    int *appo = new int[high-low+1];    //Vettore di appoggio
                                    //in questo vettore ricopieremo
                                    //in ordine gli elementi

    i=0; //I indichera` la prima posizione libera del vettore appo
    h=low; //Dove inizia il primo sottovettore
    j=mid+1; //Dove inizia il secondo sottovettore.
    //Osservazione: in ogni suddivisione mergesort produce due
    //sottovettori senza soluzione di continuita`.

    while ((h <= mid) and (j<=high)) {
        if(v[h] <= v[j]) {
            appo[i]= v[h];  //Ricopia l'elemento piu` piccolo
                            //dal sottovettore di sx
            h++;            //Incrementa indice vettore sx
        }
        else {
            appo[i] = v[j]; //Ricopia da dx
            j++;            //Incrementa indice dx
        }

        i++; //Incrementa indice vettore appo
    }
    //Qui finsce il while. A questo punto se uno dei due sottovettori
    //non e` vuoto, per costruzione conterra` elementi >= di tutti
    //quelli gia` ricopiati in appo.
    //Riverso quindi in appo gli elementi residui senza fare controlli
    // sui valori

    if(h > mid) { //Vuol dire che il sottovettore di sx e` vuoto

        for (int k = j; k <= high; k++) {
            appo[i] = v[k];
            i++;
        }
    }
    else { //E` il sottovettore di dx ad essere vuoto

        for (int k = h; k <= mid; k++) {
            appo[i] = v[k];
            i++;
        }
    }

    //Qui il vettore appo contiene i due sottovettori "fusi"
    //in modo ordinato.
    //Ricopio la sequenza ordinata nel vettore originale.

    for(int k=low; k<=high; k++)
        v[k]=appo[k-low];   //Ricordate che il vettore di
                            //appoggio ha indici a partire da 0

    //Finto: rimuovo il vettore di appoggio.
    delete [] appo;
}



