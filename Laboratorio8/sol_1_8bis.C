#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void chiediInput(int*, double*, double*);
void riempi(double [], int);
double * generaArrayGauss(int,double,double);

int main(){

   int quanti = 0;
   double media = 0.;
   double stddev = 0.;

   double *dati = NULL;


   chiediInput(&quanti,&media,&stddev);

   srand(time(NULL));

   cout << endl << "quanti, media, stdeddev: " << quanti << "\t" << media << "\t" << stddev << endl;
   
   cout << "\n quanto vale dati prima? " << dati << endl;

   dati = generaArrayGauss(quanti,media,stddev);
   
   cout << "\n quanto vale dati dopo? " << dati << endl;
   
   cout << endl << "seconda stampa (dati[i])" << endl;

   for(int i=0; i< quanti; i++)
      cout << setw(15) << dati[i];
   
   cout << endl;

   cout << endl;

   delete [] dati;

   return 0;
}


void chiediInput(int* n, double* m, double* s){

   do{
    cout << endl << "Inserire numero, media, stddev: ";
    cin >> *n >> *m >> *s;
   } while (*n <= 0 || *s <= 0 );

}

void riempi(double poldo[], int size){

   for(int i=0; i<size; i++){
      poldo[i] = (double)rand()/RAND_MAX;
      cout << setw(15) << poldo[i];
   }

}

double * generaArrayGauss(int n, double m ,double s){
   
   //Alloca nello heap l'array
   double * v = new double[n];
   riempi(v,n);

   return v;
}