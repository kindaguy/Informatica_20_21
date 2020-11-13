#include <iostream>
#include <cmath>

using namespace std;

void modificaint(int *);
void modificadouble(double *);

int main(){

    int a;
    double b;

    int appoa;
    double appob;

    int *pi = &a;
    double *pd = &b;


    cout << endl << "Inserire a e b.";
    cin >> a >> b;

    //Ricopio valori di a e b per uso futuro.
    
    appoa=a;
    
    appob=b;
    
    *pi = 3* (*pi);
    *pd = sqrt(*pd);

    cout << "a modificato: " << a  << endl;
    cout << "b modificato: " << b << endl;

    //Ripristino valori originali di a e b;
    
    a=appoa;
    b=appob;

    cout << endl << "Delegando a funzioni..."<< endl;

    modificaint(&a);
    modificadouble(&b);

    cout << "a modificato: " << a  << endl;
    cout << "b modificato: " << b << endl;

    return 0;

}

void modificaint(int *p){
    *p = 3* (*p);
}

void modificadouble(double *p){
    *p = sqrt(*p);
}
