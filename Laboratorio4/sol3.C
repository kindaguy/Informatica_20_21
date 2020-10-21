#include <iostream>

using namespace std;

int is_multi(int,int);
bool is_multi_bool(int,int);

int main(){
    
    int a,b;

    int ans1;
    bool ans2;

    //Chiediamo i numeri positivi
    do{
        cout << endl << "Inserire due numeri interi positivi: ";
        cin >>a >>b;
    } while(a<0 or b<0);
    
    ans1=is_multi(a,b);
    
    ans2=is_multi_bool(a,b);

    
    if(ans1==1)
        cout<< "is_multi says a=q*b" << endl;
    else
        cout << "is_multi says a!=q*b" << endl;

    if(ans2)
        cout<< "is_multi_bool says a=q*b" << endl;
    else
        cout << "is_multi_bool says a!=q*b" << endl;

    cout << endl << "Interesting point: " << endl;

    //The standard says that true is anything ==1, false is any other value!

    if(ans1)
        cout<< "is_multi says a=q*b" << endl;
    else
        cout << "is_multi says a!=q*b" << endl;


    return 0;
}

int is_multi(int a, int b){
    
    if(a%b == 0)
        return 1;
    else
        return 0;

}

bool is_multi_bool(int a, int b){
    
    if(a%b == 0)
        return true;
    else
        return false;

}
