#include <iostream>

using namespace std;


int main(){

    int v[10]; //Dichiaro vettore 10 interi

    int conta=0;

    int appo;

    int accu=0;
    int accu2=0;

    float media, varianza;
    
    int min,max;


    //Caricamento: solo numeri positivi e terminazione con zero.

    cout << endl << "Inserire numero positivo (zero per terminare): " ;

    cin >> appo;

    while(appo!=0 and conta <10){
        if(appo>0){ //Solo se il dato e` buono
            v[conta]=appo;
            conta++;
        } //altrimenti lo ignoro
        
        //Ultima parte: richiedi e leggi nuovo numero
        if(conta<10){
            cout << endl << "Inserire numero positivo (zero per terminare): " ;
            cin >> appo;
        }
        else{
            cout <<endl << "Numero massimo di elementi memorizzabili raggiunto!" << endl;
        }

    }

    //A questo punto procedo solo se l'utente ha inserito almeno un numero, altrimenti non ha
    //senso fare nulla.
 
    if(conta > 0){
        //Calcolo media
        for(int i=0; i<conta; i++){
         //Attenzione: l'indice i esiste solo in questo blocco!
            accu +=v[i];
        }//Alla fine del ciclo accu contiene la somma dei valori.
        
        media  = (float)accu/conta;

        for(int i=0; i<conta; i++){
        //Attenzione: l'indice i esiste solo in questo blocco!
            accu2+=v[i]*v[i];
        }//Alla fine del ciclo accu2 contiene la somma dei quadrati dei valori.
        
        varianza = (float) accu2/conta - media*media;

        //Calcolo minimo e massimo:
        //Idea: inizialmente dico che il minimo/massimo e` il primo elemento dell'array
        //Poi scandisco gli elementi rimanenti dell'array e, se necessario,
        //aggiorno i valori del minimo e del massimo
        
        min=v[0];
        max=v[0];

        for( int i=1; i<conta; i++){
            if(v[i]<min)
                min=v[i];
            if(v[i]>max)
                max=v[i];
        }
        
        cout << endl << "Risultato: " <<endl;
        cout << "\tMedia:  " << media << endl;
        cout << "\tVarianza  " << varianza << endl;
        cout << "\tMin:  " << min<< endl;
        cout << "\tMax:  " << max << endl;


    }
    else{
        cout << endl << "Nessun valore valido inserito. Nessuna statistica disponibile!" << endl;

    }
    
    return 0;

}
