#include <iostream>
#include <cstdlib>
#include <ctime>

//Librerie di RooT:
//TApplication.h: contiene l'ecosistema di entita` che
//consentiranno a RooT di funzionare, tra cui la classe
//TApplication. Va sempre inclusa.
#include "TApplication.h"

//TGraph.h: definisce la classe TGraph che consente di 
//disgnare grafici di dispersione.
#include "TGraph.h"

//Altro non vi serve sapere per ora.

using namespace std;

int main(){

   int size = 0;
   double *posx = NULL;
   double *posy = NULL;

   cout << "Inserire numero punti: ";
   cin  >> size;

   //Alloco i vettori.
   posx = new double[size];
   posy = new double[size];
   srand(time(NULL));

   //Riempio in qualche modo il vettore delle
   //ascisse e delle ordinate.

   for(int i=0; i<size; i++){
      posx[i] =  (float)i/size;
      posy[i] = 0.2 + posx[i]*0.3 + 0.2*(float)rand()/RAND_MAX;
   }

   //Qui inizia la parte di RooT. 
   //Deroghiamo alla regola di dichiarare tutte le variabili in testa.
   
   //Portate pazienza, si usa cosi`....
   TApplication app("Applicazione",0,0);
   //Qui ho creato l'ambiente per poter usare RooT.

   //Ora procedo a preparare quanto serve per lo scatterplot.
   TGraph scatter(size,posx,posy);

   //OK: qualsiasi cosa stia succedendo, le informazioni che servono
   //per disegnare lo scatterplot sono:
   //-Numero di punti (int)
   //-Vettore delle ascisse (float/double)
   //-Vettore delle ordinate (float/double)
   //! I due vettori devono avere stessa dimensione e 
   //dimensione maggiore o uguale del numero di punti

   //A questo punto lo scatter e` pronto ma non e` ancora
   //stato disegnato.

   scatter.Draw("A*");
   //Disegna tutti i punti usando * come marker

   app.Run();
   //Qui RooT manda il disegno al "sistema", che fa comparire la finestra.
   //Questo blocca l'esecuzione. Per terminare  "CTRL-C ".

   delete [] posx;
   delete [] posy;

   return 0;
}
