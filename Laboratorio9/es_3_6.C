#include <iostream>

using namespace std;

//Definisco un record puntoMat
struct puntoMat{

  double x;
  double y;
  char colore;
  int carica;
  double massa; 

};
//...dichiarando quindi un nuovo tipo di dato.


int main(){

   puntoMat punto;

   cout << endl <<"Inserire descrizione punto: ";
   
   //questa riga legge la descrizione di un singolo punto.
   cin >> punto.x >> punto.y >> punto.colore >> punto.carica >> punto.massa; 
   //file_in >> punto.x >> punto.y >> punto.colore >> punto.carica >> punto.massa; 


   return 0;
}