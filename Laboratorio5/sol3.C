#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

#define MM 50
#define NN_BASE 100
using namespace std;

double acaso_double(double,double);

int withincircle(double,double);

int countwithin(int);

double singlemeasure(int);

double media(double [],int);

double varianzaC(double [],int);


int main(){

    int nn;

    //M=50 memorizzato come costante (vedi sopra).

    double vmisure[MM];

    double estM, estSD;

    srand(time(NULL));

    for(int k=1; k <= 5; k++){

        //Inizializzo numero di punti

        nn = k* NN_BASE;

        for(int i=0; i<MM; i++)
            vmisure[i]=singlemeasure(nn);

        estM = media(vmisure,MM);
        estSD = sqrt(varianzaC(vmisure,MM));

        cout << endl << "Numero punti: " << nn;
        cout << endl << "\tStima pi: " << estM ;
        cout << endl << "\tFluttuazioni: " << estSD;
    }
    return 0;
}


double acaso_double(double min,double max){

    double num;
    double appo;

    //Genero un numero a caso tra zero e uno in doppia precisione
    appo = (double) rand()/RAND_MAX;

    num = min+ appo * (max-min);

    return num;

}

int withincircle(double x,double y){
    
    if(x*x+y*y <= 1)
        return 1;
    else
        return 0;
}

int countwithin(int n){

    double x,y;

    //Conta il numero di punti estratti interni alla circonferenza
    //di raggio unitario e centro nell'origine;
    
    int in=0;

    for(int i=0; i<n; i++){
        x=acaso_double(-1.,1.);
        y=acaso_double(-1.,1.);
        //Sommo a in il valore restituito dalla chiamata di 
        //withincircle a cui passo le coordinate del punto
        //estratte qui sopra...
        
        in += withincircle(x,y);
    }
    //Restituisco in, che contiente il numero di punti
    //nel cerchio...
    return in;

}

double singlemeasure(int n){

    //Siccome:
    //m(E)=4
    //r=1
    //...

    return (double) countwithin(n)/n * 4;

}

double media(double v[], int dim){
    double accu=0;

    for(int i=0; i<dim; i++)
        accu += v[i];

    return accu/dim;

}

double varianzaC(double v[],int dim){
    double accu2=0;

    double m;

    for(int i=0; i<dim; i++)
        accu2 += v[i]*v[i];

    m=media(v,dim);

    return (accu2/dim - m*m);

}
