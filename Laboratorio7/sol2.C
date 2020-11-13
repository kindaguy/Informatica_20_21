#include <iostream>

using namespace std;

void scambia(int *, int *);

int main(){

    int a,b;

    cout << endl << "Inserire due valori interi: ";
    cin >> a >> b;

    cout << endl <<"a= "<< a;
    cout << endl <<"b= "<<b;

    cout << endl << "scambio..." << endl;

    //Ricordatevi che scambia si aspetta i due indirizzi delle
    //variabili il cui contenuto va scambiato....
    scambia(&a,&b);

    cout << endl <<"a= "<< a;
    cout << endl <<"b= "<<b;




 return 0;
}

void scambia(int *p1, int *p2){

    int appo;
    appo = *p1;
    *p1 = *p2;
    *p2 = appo;
}
