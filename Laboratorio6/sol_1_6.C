#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

//Numero rilevazioni traiettoria
#define NN 100
#define MM 10
#define PIGRECO 3.14159
#define VEL 0.2
#define POS0 0.3

typedef double traiettoria[NN];

using namespace std;

void riempiArrayGauss(double [], int, double, double);
double acasoRaz(double, double);


int main(){

   
   
   double e[NN];

   traiettoria pos;

   traiettoria esperimento[MM];

   ofstream file_out;

   srand(time(NULL));

   riempiArrayGauss(e,NN,0.,0.1);

   for(int i=0; i<NN; i++){
      pos[i]= VEL*i + POS0 + e[i];
   }

   
   
   file_out.open("datiMoto.dat");
   
   for(int i=0; i<NN; i++){

      file_out << i << "\t" << pos[i] << endl;
      
      //DEBUG
      cout << i << "\t" << pos[i] << endl;

   }
   
   file_out.close();

   for(int j=0; j<MM; j++){
      //Per ogni traiettoria

      //1-Genera errori di rilevazione
      riempiArrayGauss(e,NN,0.,0.1);


      for(int i=0; i<NN; i++){
         //Per ogni rilevazione i della j-esima traiettoria
         esperimento[j][i] = VEL*i + POS0 + e[i];
      }

   }

   file_out.open("esperimento.dat");

   file_out << MM << endl;
   file_out << NN << endl;

   //Scrivo una traiettoria per riga

   for(int j=0; j< MM; j++){
     
     for(int i=0; i<NN; i++){
        
        file_out << esperimento[j][i] << "\t";
       
     }
     //Andiamo a capo solo tra una traiettoria e l'altra.
     file_out << endl;

   }

   file_out << endl;


   file_out.close();


   return 0;
}

double acasoRaz(double a, double b){

   return  (double) rand()/RAND_MAX *(b-a)+a;


}

void riempiArrayGauss(double v[], int num, double m, double std){

      for(int i=0; i< num; i++){

            v[i] = m + std * sqrt(-2.*log(acasoRaz(0,1)))*cos(2*PIGRECO*acasoRaz(0,1));

      }



}