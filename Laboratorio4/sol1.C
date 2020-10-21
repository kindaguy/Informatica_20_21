#include <iostream>

using namespace std;

int main(){

    float v[10];

    float num;

    //Chiedo il numero
    cout << endl << "Inserire numero: ";
    cin >> num;

    //I primi due valori sono semplicissimi!
    v[0]=1.f; //#.f costante numerica float.
    v[1]=num;
    
    //Riempio la parte rimanente del vettore.
    for(int i=2; i<10; i++)
        v[i]=v[i-1]*num;

    //Stampo risultato:

    cout << endl;
    for(int i=0; i<10; i++)
        cout << endl << "potenza "<< i <<"-esima: " << v[i];

    cout << endl;

    return 0;
}
