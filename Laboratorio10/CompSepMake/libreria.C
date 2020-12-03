/**********************************************/
/*
File sorgente: stesso nome del .h con suffisso diverso
Deve contenere le DEFINIZIONI delle funzioni dichiarate in 
libreria.h
*/
/**********************************************/


#include "libreria.h"


double **caricaMatrice(char nomefile[], int * pnr, int *pnc){

   //Importo dati DA file
   ifstream file_in;
   double **m = NULL;
   int nrighe=0, ncol=0;

   file_in.open(nomefile);

   if( file_in.fail()){
      cout << endl << "Problema apertura file. Esco!" << endl;
      //Attenzione: se qualcosa va storto restituisco NULL.
      //Chi invoca la funzione deciderà cosa fare...
      return NULL;
   }

   //Se tutto va bene....
   //Leggo numero di righe e di colonne.
   file_in >> nrighe >> ncol;

   //Attenzione che nrighe e ncol sono locali,
   //le uso per comodita`...
   //mi ricordo di esportare il valore.
   *pnr = nrighe;
   *pnc = ncol;
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

  stampaMatrice(m,nrighe,ncol);
   //Restituisco il contenuto di m
   //che e` proprio l'indirizzo della
   //matrice
   return m;
}

void stampaMatrice(double **m, int nrows, int ncols){

   cout << endl << "Stampo matrice di " << nrows <<" righe e " << ncols <<"colonne: " ;
   for(int i=0; i< nrows; i++){
      cout << endl;
      for(int j = 0; j<ncols; j++){
         cout << setw(10) << m[i][j];
      }
   }
   cout << endl;
}


double *generavmedie(double **m, int nrows, int ncols){
   double *vmedie = new double[nrows];
   //Calcolo la velocità media per ogni traiettoria
   for(int i=0; i<nrows; i++){
      vmedie[i] = (m[i][ncols-1]-m[i][0])/ncols;
   }

   //Restituisco il contenunto di vmedie
   //che e` proprio l'indirizzo del vettore.
   return vmedie;
}


double *genera_vpos_medie(double **m, int nrows, int ncols){

   double *vposmedie = new double[ncols];
 
 //Per ogni colonna
   for(int j=0; j<ncols; j++ ){
      vposmedie[j]=0;
      for(int i=0; i<nrows; i++){
         vposmedie[j]+=m[i][j];
      }
      vposmedie[j] /= nrows;
   }

   return vposmedie;
}

//Come sopra ma per le varianze.
double *genera_vpos_stddev(double **m, int nrows, int ncols){
  
  double appom;
  double *vposmedie2 = new double[ncols];

  for (int j = 0; j < ncols; j++)
  {
     appom= 0;
     vposmedie2[j] = 0;
     for (int i = 0; i < nrows; i++)
     {
        appom += m[i][j];
        vposmedie2[j] += pow(m[i][j], 2);
     }
     appom /= nrows;
     vposmedie2[j] = vposmedie2[j] / nrows - pow(appom, 2);
  }

  return vposmedie2;
}