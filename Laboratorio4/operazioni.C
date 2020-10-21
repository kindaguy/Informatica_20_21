#include <iostream>

using namespace std;

int main(){

    int a, b, q;
    float r;

    cout << endl << "Inserire dividendo e divisore: ";
    cin >> a >>b;

    q= a/b;
    cout << endl << "q= " << q << endl;

    r=a/b; //Non e` il tipo della variabile di destinazione a 
    //determinare il tipo dell'operazione sul RHS!

    cout << endl << "r sbagliato = " <<r << endl;

    r= (float)a/b;

    cout << endl << "r giusto = " <<r << endl;

    return 0;
}
