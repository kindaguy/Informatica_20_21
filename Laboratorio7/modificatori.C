#include <iostream>
//Questa libreria include i manipolatori di stream, che consentono di formattare
//per benino gli output
#include <iomanip>

#define NR 4
#define NC 3
#define FIELDW 10

using namespace std;


int main(){

    //Dichiaro una matrice di NR righe e NC colonne
    int matr[NR][NC];

    //La riempio in qualche modo

    for(int i=0; i<NR; i++){//Per ogni riga
        for(int j=0; j<NC; j++){//Per ogni colonna
            matr[i][j]=i*NC+j;
        }
    }
    //Fine caricamento
    
    //Adesso stampo
    
    for(int i=0; i<NR; i++){
        //Vado a capo prima di stampare una riga
        cout << endl;
        for(int j=0; j<NC; j++){
            //setw(n) imposta la larghezza del campo dedicato
            //al SOLO DATO CHE SEGUE. In questo caso il campo
            //ha larghezza FIELDW = 10 caratteri.
            cout << setw(FIELDW) << matr[i][j];
        }
    }
    //Vado di nuovo a capo
    cout << endl;
}
