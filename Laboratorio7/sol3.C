#include <iostream>
#include <cmath>


#define NN 10

using namespace std;


float  media(int [], int);

float  varianzaC(int [],int);

int minimo(int [], int);

int massimo(int [],int);

void statistiche(int [], int, float *, float *, int *, int *);


int main(){

    int vett[NN]={1,2,3,4,5,6,7,8,9,10};

    float valmedia;
    float valstddev;
    int valminimo;
    int valmassimo;

    statistiche(vett,NN,&valmedia,&valstddev,&valminimo,&valmassimo);


    cout << endl << "media:  " << valmedia;
    cout << endl << "stddev  " << valstddev;
    cout << endl << "minimo:  " << valminimo;
    cout << endl << "massimo:  " << valmassimo;
    cout << endl;

    return 0;
}



void statistiche(int v[], int dim, float *pmedia, float *pstddev, int *pmin, int *pmax){

    *pmedia = media(v,dim);
    *pstddev = sqrt(varianzaC(v,dim));
    *pmin = minimo(v,dim);
    *pmax = massimo(v,dim);
}


float  media(int v[], int dim){
    int  accu=0;

    for(int i=0; i<dim; i++)
        accu += v[i];

    return (float) accu/dim;

}

float varianzaC(int v[],int dim){
    int accu2=0;

    float  m;

    for(int i=0; i<dim; i++)
        accu2 += v[i]*v[i];

    m=media(v,dim);

    return ((float)accu2/dim - m*m);

}
int minimo(int v[], int dim){

     int m = v[0];

     for(int i=1; i<dim; i++)
         if(v[i]<m)
             m=v[i];

     return m;

}
int massimo(int v[],int dim){

     int m = v[0];

     for(int i=1; i<dim; i++)
         if(v[i]>m)
             m=v[i];

     return m;

}

