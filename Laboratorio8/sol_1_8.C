#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void chiediInput(int*, double*, double*);
void riempi(double [], int);

int main(){

   int quanti = 0;
   double media = 0.;
   double stddev = 0.;

   double *dati = NULL;


   chiediInput(&quanti,&media,&stddev);


   cout << endl << "quanti, media, stdeddev: " << quanti << "\t" << media << "\t" << stddev << endl;
   
   cout << "\n quanto vale dati prima? " << dati << endl; 
   dati = new double[quanti];
   cout << "\n quanto vale dati dopo? " << dati << endl;
   //cout << endl << sizeof(dati) << endl;

   srand(time(NULL));

   riempi(dati, quanti);



   cout << endl;
   return 0;
}


void chiediInput(int* n, double* m, double* s){

   do{
    cout << endl << "Inserire numero, media, stddev: ";
    cin >> *n >> *m >> *s;
   } while (*n <= 0 || *s <= 0 );

}

void riempi(double v[], int size){

   for(int i=0; i<size; i++){
      v[i] = (double)rand()/RAND_MAX;
      cout << setw(15) << v[i];
   }

}