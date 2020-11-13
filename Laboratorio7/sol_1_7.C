#include <iostream>

using namespace std;

void modificaInt(int *);

int main(){

   int a = 5;
   int c = 10;
   double b = 0.1;

   int * pi;
   double * pd;
   //Scrivi in p l'indirizzo di a
   pi = &a;

   //Dopo questo assegnamento *p e`  un alias di a...
   //quindi potro` scrivere *p ogni volta che vorro` scrivere
   //a

   *pi = 3 * (*pi);
   
   //modificaInt(pi);
   modificaInt(&a);

   cout << endl << a << endl;
   

   return 0;
}

void modificaInt(int * p){

      *p = 3 * (*p);

}