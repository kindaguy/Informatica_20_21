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

using namespace std;

//#define NN 100
//#define MM 100

//Questa funzione, caricherà la matrice dal file
//indicato e 
//restituira` l'indirizzo dove avra` allocato
//la memoria e le dimensioni della matrice
//per "side effect"
double **caricaMatrice(char [], int *, int *);
void stampaMatrice(double **, int, int);

//Questa funzione prende in ingresso la matrice e 
//le sue dimensioni, per poi allocare e riempire il
//vettore delle velocita` medie
double *generavmedie(double **, int, int);

//Genero vettore delle posizioni medie
//A partire dalla matrice e dalle sue
//dimensioni
double *genera_vpos_medie(double **, int, int);
//Come sopra ma per le varianze.
double *genera_vpos_stddev(double **, int, int);


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