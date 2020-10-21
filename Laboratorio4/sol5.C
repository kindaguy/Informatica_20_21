#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int acaso_int(int,int);

double acaso_double(double,double);

int main(){

    int min,max;
    double dmin,dmax;

    int acaso;
    double dacaso;

    //Inizializziamo seme generatore rand() usando 
    //il tempo macchina in secondi....
    srand(time(NULL));
    //Ricordatevi che questa istruzione va eseguita una
    //sola volta in tutto il codice.

    cout << endl << "Inserire minimo e massimo intervallo per intero: ";
    cin >> min >> max;

    //Numero a caso intero tra min e max
    acaso = acaso_int(min,max);

    cout << endl << "A caso int [" <<min << "," << max <<"] = " << acaso << endl;
    cout << endl << "Inserire minimo e massimo intervallo per double ";
    cin >> dmin >> dmax;

     //Numero a caso intero tra min e max
    dacaso = acaso_double(min,max);

    cout << endl << "A caso double [" <<min << "," << max <<"] = " << dacaso << endl;

    return 0;
}


int acaso_int(int min,int max){

    int num;
    num = min+ rand()%(max-min);

    return num;

}


double acaso_double(double min,double max){

    double num;
    double appo;

    //Genero un numero a caso tra zero e uno in doppia precisione
    appo = (double) rand()/RAND_MAX;

    num = min+ appo * (max-min);

    return num;

}
