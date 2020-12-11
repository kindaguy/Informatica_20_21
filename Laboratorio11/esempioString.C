#include <iostream>
#include <fstream>

//Questo include la "classe"  string. Fa tante cose interessanti. Ne vedremo alcune.
#include <string>

using namespace std;

int main(){
    
    string unaStringa;
    char appo[100];

    ifstream filein;
    int conta = 0;



    // unaStringa = "Ciao a...";
    // cout << endl << unaStringa + "...chi vuoi salutare? ";
    // cin >> appo;
    // cout << endl << unaStringa + " " + appo;

   cout << endl << "Nome del file da aprire (senza .dat)";
   cin >> unaStringa;
   cout << endl << "Apro: " << unaStringa + ".dat" << endl; 

   unaStringa += ".dat";

   filein.open(unaStringa);
   
   if (filein.fail()){
       cout << "Probema apertura file" << unaStringa <<"; ESCO "<< endl;
       return -1;
   }


   //Assumendo che i punti siano descritti riga per riga, conto le righe....
  
   //Uso la fuuzione getline, documentata qui
   //http://www.cplusplus.com/reference/string/string/getline/
   //con un ciclo Spoletini
   //Nota: di default getline individua il finelinea nel carattere "a-capo"
   //o '\n', ma si può modificare, se necessario.

   //Prima lettura fuori ciclo
   getline(filein,unaStringa);

   while (!filein.eof()){
       conta++;
       //Lettura prima di uscire
       getline(filein,unaStringa);
   }

   filein.close();

   cout << "Numero di coppie su file: " << conta << endl; 

    return 0;
}
