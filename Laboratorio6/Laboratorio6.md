# Laboratorio 6: lettura e scrittura da files, simulazione esperimento.

Proviamo un nuovo strumento: i files. I dati contenuti nei files sopravvivono alla chiusura del programma (e anche allo spegnimento del computer) quindi sono un ottimo mezzo per archiviare e passare informazione. Useremo i files per registrare i dati associati ad un esperimento di rilevazione della posizione in funzione del tempo per un punto materiale che  si muove di moto rettilineo uniforme.

## Esercizio 1


1.  Dichiarare e definire una procedura

	__void  riempiArrayGauss(double [], int dim, double m, double std);__


	che presi in ingresso il vettore, il numero di dati da generare (garantito 	 essere minore della lunghezza dell'array), la media e la deviazione standard della distribuzione Gaussiana da cui estrarli, riempia  riempia di numeri Gaussiani opprortnuamente derivati attraverso la trasformazione di Box-Muller.

1. Stampare quindi il vettore dal __main__ e calcolare e stampare a video la media e la deviazione standard del campione del vettore.

1. Dichiarare un vettore __pos__ di N=100 __double__ e riempirlo di valori generati attraverso la relazione

	__pos[i] = 0.2 *i + 0.3 + e[i]__
		
	dove __e[i]__ è la i-esima componente del vettore di numeri Gaussiani estratti da una popolazione di media zero e deviazione standard 0.1

1. Scrivere i valori contenuti nell'array __pos__ in un file. 
Piu` precisamente ogni riga del file dovrà contenere una coppia __(i,pos[i])__ nel formato:

	__numero di misure__
	
	__i [tabulazione] pos[i]__
	
	dove __[tabulazione]__ e` il carattere di _escape_  __'\t'__.
	Quindi il nostro file conterrà nella prima riga un intero  seguito da una sequenza di coppie.

## Esercizio 2

Sfruttando tutto quanto saccheggiabile dall'esercizio precedente:

1. Generare M = 10 vettori di errori, e 10 vettori di posizioni come al punto precedente. I 10 vettori di posizioni differiranno per gli errori.

	__esperimento[i][j] = 0.2* i + 0.3  + e[i][j]__

	dove __j__ gioca il ruolo di indice di colonna (istante temporale, se volete) e __i__ è  l'indice di riga (di quale misura di moto stiamo parlando).
	
2. Registrare quanto ottenuto su un file dal nome __esperimenti.dat__ con il seguente formato:
  	__numero di misure__
  	__numero di rilevazioni di posizione per misura__
  	__i [tabulazione] esperimento[0][0] [tabulazione] esperimento[0][1] ... esperimento[0][99]__
  	__i [tabulazione] esperimento[1][0] [tabulazione] esperimento[1][1] ... esperimento[1][99]__
  	  	__i [tabulazione] esperimento[9][0] [tabulazione] esperimento[9][1] ... esperimento[9][99]__

## Esercizio 3
Scrivere un programma che, preparata una matrice (tabella) di M=10 righe e N=100 colonne, riempirla con i dati letti da __esperimenti.dat__.

Calcolare: 

1. La velocità  media per ogni traiettoria.
2. La media delle posizioni per ogni istante di tempo.
3. La deviazione standard delle posizioni per ogni istante di tempo.
