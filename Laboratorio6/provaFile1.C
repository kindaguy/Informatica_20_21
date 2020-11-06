#include <iostream>

//fstream contiene ifstream, ofstream, e fstream, ovvero
//quanto serve per mettere in comunicazione programma e
//files.

#include <fstream>

using namespace std;


int main(){

   ifstream file_in;
   ofstream file_out;

   int appo;

   file_in.open("dati.dat");
   //Se tutto va bene (il file c'e` ed e` nella stessa cartella 
   //del programma), lo stream e` aperto (flusso file -> programma)

   file_out.open("copia_dati.dat");
    //Se tutto va bene lo stream e` aperto (flusso programma -> file)

   for(int i=0; i<10; i++){
      file_in >> appo;
      cout << endl << appo;
      file_out << endl << appo;
   }

   cout << endl;
   file_out << endl;


   return 0;
}