#include <iostream>
#include <cstdlib>
#include <ctime>
//Un punto in R^2 e`  una coppia ordinata di valori in R

using namespace std;

#define NUM_PUNTI 10

typedef float puntoR2[2];



int main(){

   puntoR2 punto;

   puntoR2 vpunti[NUM_PUNTI];

   //float vpunti[NUM_PUNTI][2];
   
   srand(time(NULL));
   

   punto[0] = 1;
   punto[1] = 2;

   for(int i=0; i<NUM_PUNTI;i++){
      
      //Sto caricando un vettore di puntiR2 
      //con punti a caso
      vpunti[i][0] = (float)rand()/RAND_MAX;
      vpunti[i][1] = (float)rand()/RAND_MAX;
      //Sto altrimenti detto caricando una
      //MATRICE/TABELLA di NUM_PUNTI righe
      //e 2 colonne

   }



   return 0;
}
