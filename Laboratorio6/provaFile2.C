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

//CICLO SPOLETINI

   //Il primo dato, se c'e`, va estratto prima di elaborarlo.
   //In questo modo se il file e` vuoto, non tento di elaborare nulla
   file_in >> appo;
   //Uso un while perche', normalmente, non so quanti dati contenga il
   //file e devo leggerli tutti.

   while(!file_in.eof()){

      //file_in.eof() chiede allo stream se il file e` finito.
      //se si, restituisce true, altrimenti restituisce false.
     
      //Se arrivo qui il dato c'e` sicuramente
      cout << endl << appo;
      file_out << endl << appo;

      //Come ultima istruzione tento di leggere il dato successivo.
      file_in >> appo;
   }

//CICLO SPOLETINI
   cout << endl;
   file_out << endl;

   //Chiudo flusso da file_in
   file_in.close();
   
   //Chiudo flusso da file_out
   file_out.close();



   return 0;
}