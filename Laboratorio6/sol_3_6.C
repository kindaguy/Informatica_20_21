#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#define NN 100
#define MM 100

int main(){

   int nrighe, ncol;

   double m[NN][MM];
   double vmedie[NN];

   double vposmedie[MM];
   double vposmedie2[MM];

   //Importo dati DA file
   ifstream file_in;

   file_in.open("esperimento.dat");

   if( file_in.fail()){
      cout << endl << "Problema apertura file. Esco!" << endl;
      return -1;
   }

   //Leggo numero di righe e di colonne.
   file_in >> nrighe >> ncol;
   
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

   //Per ogni riga
   for(int i=0; i< nrighe; i++){
      cout << endl;
      //Carico gli elementi (in numero pari al numero di colonne)
      for(int j=0; j<ncol; j++){
         cout << setw(10)<< m[i][j];
      }
   }
   cout << endl;

   //Calcolo la velocità media per ogni traiettoria
   for(int i=0; i<nrighe; i++){
      vmedie[i] = (m[i][ncol-1]-m[i][0])/ncol;
   }

   //Per ogni colonna
   for(int j=0; j<ncol; j++ ){
      vposmedie[j]=0;
      for(int i=0; i<nrighe; i++){
         vposmedie[i]+=m[i][j];
      }
      vposmedie[j] /= nrighe;
   }



   return 0;

}