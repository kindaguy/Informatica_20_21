#include <iostream>
#include <fstream>

using namespace std;

struct puntoMat{
   double x,y;
   char color;
   int carica;
   float massa;
};


//Funzione di caricamento da file.
//Restituisce l'indirizzo del vettore allocato oppure NULL in caso di errore.
//Il numero di elementi caricati e` salvato nella variabile intera
//passata per riferimento.

puntoMat *caricaDaFile(const char [], int *);