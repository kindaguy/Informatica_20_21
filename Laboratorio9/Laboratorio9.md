# Laboratorio 9: librerie, struct, RooT


In questo laboratorio creeremo le nostre prime librerie. Esemplificheremo l'uso delle struct e della libreria RooT per il disegno di semplici grafici.

## Esercizio 1
Seguendo quanto visto a lezione, creare una libreria contenente tutte le funzioni definite fino ad ora per la generazione di numeri casuali, tra cui:

__int acaso(int,int)__

__float acaso(float,float)__

__double acaso(double,double)__

__double boxMuller(double,double)__

La libreria dovrà anche contenere una funzione 

__void initRand()__

che inizializzi il seme del generatore di numeri casuali attraverso la ben nota istruzione 

__srand(time(NULL))__

Testare la libreria, ovvero verificare che funzioni e che funzioni correttamente, usando un semplice programma.


## Esercizio 2
Seguendo quanto visto a lezione, creare una libreria contenente alcune funzioni statistiche, come ad esempio
__double  media(int*, int)__

__float  media(float *,int)__

__double  media(double *,int)__

__double  varianza(int*, int)__

__float  varianza(float *,int)__

__double  varianza(double *,int)__

__int min(int *, int)__

__float min(float*,int)__

ecc...


## Esercizio 3

Definita il record (struttura)

struct puntoMat{

float x;
float y;
char colore;
int carica;
float massa;

};

scrivere un programma che riempia i campi chiedendo i dati all'utente, o inserendo valori generati a caso attraverso le funzioni note.


## Esercizio 4

Il file __puntiPiano.dat__ contiene la descrizione di un numero non precisato di punti materiali sul piano cartesiano. Piu` in particolare, ogni riga contiene una quintupla (x,y,col, car,m), dove (x,y) indica la posizione sul piano del punto, col il suo colore, car la carica e m la massa.

Definita il record (struttura) __struct puntoMat__ come nell'esercizio precedente, caricare dal file la descrizione di tutti i punti  presenti in un vettore di puntoMat allocato dinamicamente.

Al fine di risolvere questo esercizio, potrebbe essere conveniente ricordare che:

1. Se il numero di punti descritti nel file non e` noto, è necessario usare un _cilclo Spoletini_ per contare il numero di punti. Attenzione che per _lettura del dato_, qui si intende _lettura della descrizione completa di un punto materiale_, quindi di una quintupla.

2. Il formato del file fornito è corretto. Potete quindi stare tranquilli che ogni riga è completa di tutte le informazioni, ovvero contiene una quintupla.

3. Il numero di righe del file ovviamente potete contarlo a mano, ma far contare le righe (numero di punti) al programma fa parte dell'esercizio e delle cose che dovete saper fare, quindi non imbrogliate!

4. dopo la sua dichiarazione, __puntoMat__ è  un tipo di dato, quindi vettori di punti materiali si possono allocare come
__puntoMat * vpunti = new puntoMat[dim];__
dove __dim__ è  la dimensione del vettore.

5. Ad esempio il campo __x__ del primo elemento del vettore si può indicare con 
__vpunti[0].x__ 	
mentre il campo __colore__ della terza componente del vettore si può indicare con
__vpunti[2].colore__

## Esercizio 5
Disegnare con RooT uno scatterplot (grafico di dispersione) delle posizioni (x,y) dei punti materiali caricati nell'esercizio precedente.
