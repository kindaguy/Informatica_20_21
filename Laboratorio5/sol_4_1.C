#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


typedef double puntoR2[2];

bool withincircle(double,double);

int countwithin(int);

double singlemeasure(int);

int main(){

  


   return 0;
}


bool withincircle(double x, double y){

      if(x*x+y*y <= 1){
         return true;
      }
         
      else{
         return false;
      }
     
}

int countwithin(int n){

   puntoR2 punto;
   int conta = 0;

   for(int i=0; i<n; i++){
      
      punto[0] = acaso(-1,1);
      punto[1] = acaso(-1,1);     

      if( withincircle(punto[0],punto[1]) )
         conta++;
   }

   return conta;

}

double singlemeasure(int n){

      return ((double) countwithin(n)/n) * 4;



}