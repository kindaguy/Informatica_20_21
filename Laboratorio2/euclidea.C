#include <iostream>

using namespace std;

int main(){

    int a,b;
    int quoz, resto;

    //Stampo messaggio:
    cout << endl << "Inserire dividendo e divisiore: " ;
    
    cin >> a; //Legge da tastiera e registra valore in a
    cin >> b; //Legge da tastiera e registra valore in b
    
    //Dati acquisiti: ora procediamo
    
    resto=a;
    quoz=0;

    if(b!=0){//Allora

        //Procediamo
        while(resto-b >= 0){    //qui inizia l'elenco delle cose
                                //fino a che la condizione resto-b>=0 
                                //e` vera...
            quoz = quoz+1;
            resto = resto-b;
        } //fine delle cose fa fare nel ciclo.

        //Stampo il risultato
        cout << endl <<"Quoziente: " << quoz <<"; resto: " << resto << endl;

    }
    else{//Altrimenti
        cout <<endl <<"Divisione per zero!" << endl;
    }
    
    return 0;
}
