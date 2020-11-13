# Laboratorio 7: Puntatori e matrici

In questo laboratorio cominceremo ad utilizzare i puntatori, lavoreremo sulle matrici e impareremo ad impaginare i dati.

## Esercizio 1
1. Scrivere un programma che dichiari due variabili __a__  e __b__ di tipo rispettivamente  __int__ e __double__,  e due variabili __pi__ e __pd__ di tipo rispettivamente puntatore a __int__ e puntatore a __double__. 
Assegnare quindi ad __a__ ed a __b__ due valori letti da tastiera. Modificare il valore contenuto in __a__ in __3 * a__ e il valore contenuto in __b__ in __sqrt(b)__ usando __pi__ e __pd__. Stampare a video il risultato. 
1. Delegare a due funzioni

__void modificaint(int * p)__

__void modificadouble(double * p)__

il compito di modificare il contenuto delle variabili __a__ e __b__ del main come descritto al punto precedente.

## Esercizio 2
Definire una procedura

__void scambia(int *p1, int *p2)__

che, ricevuti in ingresso gli indirizzi di due variabili intere, ne scambi il contenuto. Verificare (nel __main__) che a seguito della chiamata della procedura i contenuti delle variabili i cui indirizzi sono stati passati a __scambia__ siano stati effettivamente scambiati.

## Esercizio 3
Scrivere una procedura 

__void statistiche(int v[], int dim, float * pmedia, float * pstddev, int * min, int * max)__

che presi in ingresso un vettore di interi (di dimensione che volete e caricato da qualche parte) e gli indirizzi di variabili opportunamente dichiarate nel __main__, calcoli la media, la deviazione standard del campione, e i valori minimo e massimo del campione e li registri nelle variabili (del __main__) i cui indirizzi sono stati passati  alla funzione.

Ricordatevi che da qualche parte avete già definito funzioni per il calcolo delle statistiche richieste: riciclate quanto più possibile il lavoro già fatto!

## Esercizio 4
1.Dichiarare una matrice __A__ di interi avente __N=4__ righe e __M=3__ colonne. Riempire quindi la matrice assegnando ad

__A[i,j]=i * M * sizeof(int) + j * sizeof(int)__ 

ricordando che __sizeof(T)__ è una funzione del linguaggio che restituisce la dimensione (in byte) del tipo passato come parametro, e che __i__ e __j__ partono da zero (ad esempio l'elemento più in alto a sinistra della matrice è __A[0,0]__).

1. Dichiarare anche una matrice __AT__ di interi di __M__ righe e __N__ colonne. Scrivere in __AT__ la matrice __A__ trasposta ovvero:

__AT[i,j]=A[j,i]__ con __i=0,1,...,M-1, j=0,1,2,..,N-1__ 


Nota: per stampare per benino le matrici potete usare (insieme agli opportuni "a capo") i _modificatori_ di stampa, il cui uso è esemplificato nel file __manipolatori.C__ presente in questa cartella. 
