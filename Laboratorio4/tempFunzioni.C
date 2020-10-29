#include <iostream> 

#define NN 20
//Dichiarazione
float f(float);

//funzione che usa array;

float media(float [NN],int);

int main(){
    

    int 
    
    int a=5;
    int b = 2;
    a%b; //Restituisce il resto della divisione Euclidea tra a e b

    int size;
    float y;
    float x;
    float z;

    float v[NN];

    //Caricamento del vettore 
    //Avro`  dati nel vettore e scritto in size quanti dati

    z = media(v,size);
    

    return 0;
}




//Definizione
float f(float x){

    float y; //Variabile locale della funzione
            //Anche x e` una variabile locale della funzione,
            //che pero`, in quanto parametro formale, viene inizializzata quando la funzione viene invocata.
   
    y =3*x+1;
    return y;

}

//Definizione della funzione media

float media(float vec[NN], int dim){
    float accu = 0;

    for(int i = 0; i < dim; i++ ){
        accu = accu+vec[i];
    }

    return accu/dim;


}