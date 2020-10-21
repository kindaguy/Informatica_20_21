#include <iostream>

using namespace std;

int main(){

    int a,b;
    
    int res=1;

    //Chiediamo i numeri positivi
    do{
        cout << endl << "Inserire due numeri interi positivi: ";
        cin >>a >>b;
    } while(a<0 or b<0);

    while(b>0){
        res *=a;
        b--;
    }
    cout << endl << "Risultato a^b: " << res << endl;

}

