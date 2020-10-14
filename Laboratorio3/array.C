#include <iostream>

using namespace std;

int main(){

    int conta=0;
    int dato;
    //int i=0;  //Questo serviva per il while
    int v[10];  //Array di 10 interi

//Ciclo Spoletini

//-prima lettura fuori dal ciclo    
    cout << endl << "Inserire dato: ";
    cin>> dato;
//-se non terminata sequenza, e c'e` ancora posto nell'array
    while(dato!=0 and conta<10){

        //Se il dato e` positivo, quindi valido
        if(dato >0){
        
            v[conta]=dato;
            conta++;
        }
        //Non mettiamo l'else: semplicemente non registriamo

        cout << endl << "Dati caricati nell'array: "<< conta << endl;
        cout << endl << "Inserire dato: ";
        cin >> dato;
    }

  
    cout << endl << "Caricati " << conta << " dati." << endl << endl;
    for(int i=0; i<conta; i++){

        cout << endl << "Elemento posizione " << i <<  " dell'array: "<<  v[i] << endl;
    }
    
    /* while(i<conta){
        cout << v[i] << endl;
        i++;
    }*/

    return 0;
}
