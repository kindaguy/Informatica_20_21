#include <iostream>

using namespace std;

int main(){

    int conta = 0;
    int accu=0;
    int accu2=0;
    int appo;
    float media, varianza;
    int min, max;

    //Ciclo Spoletini
    cout << endl << "Inserire valore positivo (zero per terminare): " ;
    cin >> appo;
    while(appo!=0){

        if(appo>0){
            if(conta == 0){//Se e` il primo dato valido (>0) inserito
                min  = appo;
                max = appo;
            }
            accu+=appo;
            accu2+=appo*appo;
            //Aggiorno minimo:
            if(appo<min)
                min=appo;
            //Aggiorno massimo:
            if(appo>max)
                max=appo;
            
            conta++;
        }

        //Leggo valore successivo
        cout << endl << "Inserire valore positivo (zero per terminare): " ;
        cin >> appo;
    
    }

    //Fine acquisizione dati. Processo risultati parziali

    //Se c'e` almeno un dato
    if(conta>0){
        media = (float) accu/conta;
        varianza = (float) accu2/conta - media*media;
        //Minimo e massimo gia` pronti
        cout << endl << "Risultato: " <<endl;
        cout << "\tMedia:  " << media << endl;
        cout << "\tVarianza  " << varianza << endl;
        cout << "\tMin:  " << min<< endl;
        cout << "\tMax:  " << max << endl;
    }
    else{
        cout << endl << "Nessun dato valido inserito. Statistiche non disponibili"  << endl;
    }
    return 0;
}
