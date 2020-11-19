//Programma che copia dati interi da un file che si
//trova nella
//stessa cartella in cui si trova il nostro programma in un altro file di nome "datiCopia.dat",
//sempre nella stessa cartella in cui si trova il nostro programma.
//Il programma deve inoltre stampare il numero di interi copiati.
#include <iostream>
//La libreria fstream definisce i tipi di dato (classi) ifstream e ofstream
#include <fstream>

using namespace std;



int main(){
    
    int appo;
    int conta=0;
    
    ifstream ingresso;
    ofstream uscita;

    ingresso.open("dati.dat");

    //Controllo che lo stream di input (ifstream) sia stato associato correttamente al file di input, ovvero che il file
    //di input esista.

    if(ingresso.fail()){
        //ingresso.fail() controlla se uno stream e` in errore. Se si restituisce true, altrimenti
        //false.
        //Noterete, come per open, una strana sintassi che semanticamente significa far fare qualche
        //cosa ad una variabile.
        //Per ora accettate passivamente. Tutto diventera` chiaro quando parleremo di classi e
        //oggetti.

        cout << endl << "Problema apertura file ingresso:  esco dal programma" << endl;
        return -1;
    }

    //Non metto else: se ci fossero problemi esco

    //Qui associo il file "datiCopia.dat"  ad uno stream di output.

    uscita.open("datiCopia.dat");

    //Attenzione: se datiCopia non esiste, viene creato ex novo, se esiste viene azzerato e poi
    //sovrascritto.
    
    //In questo programma e` garantito che il file, se c'e` (vedi sopra) contiene 10 interi.
    //Quindi uso un semplice for.


    //Non sappiamo quanti dati ci sono nel file, e questi potrebbero essere zero!
    //Quindi ciclo Spoletini
    
    //Prima lettura fuori dal ciclo
    ingresso >>appo;
    
    
    //ingresso.eof() restituisce true se il file e` finito (tutti i byte letti), false altrimenti.
    //ingresso.eof() diventa true quando si cerca di leggere altri dati da un file esaurito.

    while(!ingresso.eof()){
        uscita << appo << " ";
        conta++;
        //Lettura dato successivo prima di ritestare la condizione.
        ingresso  >> appo;
    }
    
    cout << endl << "Copiati: " << conta << " dati"<< endl;

    ingresso.close();
    uscita.close();


    return 0;
}
