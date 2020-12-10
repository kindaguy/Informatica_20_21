# Laboratorio 11: algoritmi di ordinamento, regressione con RooT 


## Esercizio 1
Implementare la procedura __selectionSort__ discussa a lezione per vettori di interi. Testate la correttezza su vettori di dimensione ridotta (ad es. 10) così da poter controllare il risultato.

## Esercizio 2

Partendo dalla definizione della procedura __merge__ presentata nel file __prova_merge_monca_cpp__ che trovate in questa cartella, implementare la procedura __mergeSort__ completa per vettori di interi.


## Esercizio 3

Modificare la funzione __mergesort__  in una funzione __mergesortInv__ che ordini gli elementi del vettore in ordine monotono non crescente.


## Esercizio 4

Sia definita la struttura

__struct complesso{
	float re;
	float im
};__

Caricare un vettore di lunghezza __n__  valori __complesso__, con __n__ determinato a _runtime_ (riempitelo come volete: da tastiera, da file, di numeri casuali,...).
Ordinare il vettore in ordine di _modulo_ crescente, usando la procedura __mergesort__ definita nell'Esercizio 1, opportunamente modificata.

## Esercizio 5

Caricati dal file __datiMoto.dat__ un numero imprecisato di coppie di razionali (in singola precisione), ciascuna rappresentate le coordinate <img src="https://render.githubusercontent.com/render/math?math=(x_i,y_i)"> di un punto sul piano cartesiano

1. Stampare a video il numero delle coppie caricate.
2. Visualizzare uno scatterplot dei punti.


## Esercizio 6

Caricati ancora una volta i dati dal file __datiMoto.dat__, stampare a video il numero di dati. Calcolare poi i coefficienti __q__ e __m__ della retta di regressione utilizzando le formule:

<img src="https://render.githubusercontent.com/render/math?math= b=S_{xy}/S_{xx}">
<img src="https://render.githubusercontent.com/render/math?math= a=\bar{y} - b \bar{x}">

dove in 

<img src="https://render.githubusercontent.com/render/math?math= S_{xx} = \frac{1}{N} \sum_{i=1}^N (x_i-\bar{x})^2">

riconosciamo la varianza del campione, mentre

<img src="https://render.githubusercontent.com/render/math?math= S_{xy} = \frac{1}{N} \sum_{i=1}^N (x_i - \bar{x})((y_i - \bar{y}))">

quantifica la correlazione tra x e y.




Caricato un vettore di __complesso__ (vedi esercizio 3) di numeri aventi parte reale e parte immaginaria estratti da una popolazione Gaussiana standard, disegnare uno scatterploto dei numeri complessi, rappresentanto la parte reale in ascissa e la parte complessa in ordinata.
Usare il programma descritto in __provaFit.C__ come riferimento.

