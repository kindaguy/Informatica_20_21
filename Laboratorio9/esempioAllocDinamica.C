/**************************************************/
/*Riprendiamo la soluzione dell'esercizio 3 della
settimana 6, questa volta usando l'allocazione 
dinamica della memoria*/
/**************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

//#define NN 100
//#define MM 100


int main(){

   int nrighe, ncol;

   //double m[NN][MM];
   double **m;

   
   //double vmedie[NN];
   double *vmedie;


   // double vposmedie[MM];
   // double vposmedie2[MM];
   double *vposmedie;
   double *vposmedie2;

   //Importo dati DA file
   ifstream file_in;

   file_in.open("esperimento.dat");

   if( file_in.fail()){
      cout << endl << "Problema apertura file. Esco!" << endl;
      return -1;
   }

   //Leggo numero di righe e di colonne.
   file_in >> nrighe >> ncol;

   //A questo punto alloco la matrice dinamicamente,
   //come visto la volta scorsa...
   
   //Alloco il vettore dei puntatori a riga
   m = new double *[nrighe];

   //Alloco le righe una per una...
   for(int i=0; i< nrighe;i++){
      m[i] = new double[ncol];
   }


   //La matrice e` pronta per essere usata....
   
   //Per ogni riga
   for(int i=0; i< nrighe; i++){
      //Carico gli elementi (in numero pari al numero di colonne)
      for(int j=0; j<ncol; j++){
         file_in >> m[i][j];
      }
   }

   //La matrice e` caricata

   //Il file non mi serve piu`
   file_in.close();

   //Stampa
   //Per ogni riga
   for(int i=0; i< nrighe; i++){
      cout << endl;
      //Carico gli elementi (in numero pari al numero di colonne)
      for(int j=0; j<ncol; j++){
         cout << setw(10)<< m[i][j];
      }
   }
   cout << endl;

   //Alloco il vettore delle medie
   //di dimensione pari al numero di righe
   vmedie  = new double[nrighe];

   //Calcolo la velocità media per ogni traiettoria
   for(int i=0; i<nrighe; i++){
      vmedie[i] = (m[i][ncol-1]-m[i][0])/ncol;
   }

   //Alloco i vettori delle posizioni medie e 
   //delle deviazioni standard,
   //Entrambi di dimensione pari al numero di colonne
   vposmedie = new double[ncol];
   vposmedie2 = new double[ncol];
   //Per ogni colonna
   for(int j=0; j<ncol; j++ ){
      vposmedie[j]=0;
      vposmedie2[j]=0;
      for(int i=0; i<nrighe; i++){
         vposmedie[j]+=m[i][j];
         vposmedie2[j]+=pow(m[i][j],2);
      }
      vposmedie[j] /= nrighe;
      vposmedie2[j] = vposmedie2[j]/nrighe- pow(vposmedie[j],2);
   }

   //Stampo i risultati
   for(int j=0; j<ncol;j++){
      cout << endl <<"tempo: " << j <<", posizione media: " << vposmedie[j] << ", fluttuazioni: " << vposmedie2[j]; 
   }
   cout << endl;

   //Dealloco tutto quello che ho allocato dinamicamente

   //Matrice: 
   //1-cancello le righe una per una

   for(int i=0; i<nrighe; i++)
      delete [] m[i];
   
   //Adesso cancello il vettore dei puntatori a riga
   delete [] m;

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