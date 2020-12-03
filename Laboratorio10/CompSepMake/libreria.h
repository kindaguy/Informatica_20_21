/***********************************************/
/*
File header, deve includere:
1-tutti gli include delle librerie che servono alle funzioni di libreria,
seguito da using namespace std;
2-tutte le definizioni di costanti della libreria
3-tutti i tipi di dato che la libreria usa o definisce (ad esempio typedef)
4-tutte le DICHIARAZIONI delle funzioni/procedure di libreria
5-(last but not least): un numero congruo di commenti che 
--consentano a chi usa la libreria di capire che cosa fa ciascuna funzione
--e anche il significato dei parametri (cosa che io qui non ho specificato
perche' predico bene e razzolo male...)
*/
/***********************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

//Questa funzione, caricherà la matrice dal file
//indicato e 
//restituira` l'indirizzo dove avra` allocato
//la memoria e le dimensioni della matrice
//per "side effect"
double **caricaMatrice(char [], int *, int *);
//Se volete rimuovere il warning mettete const char [] qui
// e nella corrispondente definizione della funzione caricaMatrice



void stampaMatrice(double **, int, int);

//Questa funzione prende in ingresso la matrice e 
//le sue dimensioni, per poi allocare e riempire il
//vettore delle velocita` medie
double *generavmedie(double **, int, int);

//Genero vettore delle posizioni medie
//A partire dalla matrice e dalle sue
//dimensioni
double *genera_vpos_medie(double **, int, int);
//Come sopra ma per le varianze.
double *genera_vpos_stddev(double **, int, int);

