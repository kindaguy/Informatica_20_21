/**************************************************/
/*Riprendiamo la soluzione dell'esercizio 3 della
settimana 6, questa volta usando, oltre all'allocazione 
dinamica della memoria, anche funzioni...
Delegheremo tutto il delegabile a funzioni*/
/**************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "libreria.h"

using namespace std;


int main(){

   int nr=0, nc=0;

   //double m[NN][MM];
   double **matr;

   
   //double vmedie[NN];
   double *vmedie;


   // double vposmedie[MM];
   // double vposmedie2[MM];
   double *vposmedie;
   double *vposmedie2;


   matr = caricaMatrice("esperimento.dat",&nr,&nc);
   
   
   vmedie  = generavmedie(matr, nr, nc);
   vposmedie = genera_vpos_medie(matr, nr, nc);
   vposmedie2 = genera_vpos_stddev(matr, nr, nc);

  
   
   //Stampo i risultati
   cout << endl << "Velocità medie:";
   for(int i=0; i< nr; i++){
      cout << endl << vmedie[i];
   }
   cout << endl;

   for(int j=0; j<nc;j++){
      cout << endl <<"tempo: " << j <<", posizione media: " << vposmedie[j] << ", fluttuazioni: " << vposmedie2[j]; 
   }
   cout << endl;

   //Dealloco tutto quello che ho allocato dinamicamente

   //Matrice: 
   //1-cancello le righe una per una

   for(int i=0; i<nr; i++)
      delete [] matr[i];
   
   //Adesso cancello il vettore dei puntatori a riga
   delete [] matr;

   //Ora rimuovo i rimanenti vettori allocati dinamicamente.

   delete [] vmedie;
   delete [] vposmedie2;
   delete [] vposmedie;

   //Tutto ripulito, finisco sereno.
   //Nota: la memoria allocata dinamicamente sarebbe stata comunque liberata
   //al termine del programma, ma e` buona abitudine ricordarsi di 
   //deallocare un oggetto quando non serve piu`.
   //"Da un grande potere derivano grandi responsabilita`"

   return 0;

}

