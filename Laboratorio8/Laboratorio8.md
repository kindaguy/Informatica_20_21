# Laboratorio 7: Allocazione dinamica della memoria e files.

In questo laboratorio affronteremo l'allocazione dinamica della memoria, il caricamento e la stampa di dati da/verso files.

Ricordiamo che tutte le funzioni operanti su vettori usate fino ad ora possono essere usate nello stesso modo (quindi copiate ed incollate).

## Esercizio 1
1. Scrivere un programma che, chiesto all'utente quanti numeri casuali Gaussiani di media e deviazione standard forniti in ingresso dall'utente stesso, allochi dinamicamente un vettore di __double__ di dimensione pari al numero di numeri casuali da generare e riempia il vettore con i numero casuali generati. Calcolare media e deviazione standard del campione del vettore generato.

1. Modificare il programma in modo tale che il vettore dei dati sia creato e caricato da una funzione. Più precisamente:

	1.  dichiarare e definire una funzione

	__double * generaArrayGauss(int dim, double m, double std);__


	che presi in ingresso il numero di dati da generare, la media e la deviazione standard della distribuzione Gaussiana da cui estrarli, allochi _al suo interno_ dinamicamente il vettore di __dim__ elementi di tipo __double__ , lo riempia di numeri Gaussiani opprortnuamente derivati, e restituisca l'indirizzo in cui comincia il vettore dinamico allocato.
	
	1. Stampare quindi il vettore dal __main__ e calcolare e stampare a video la media e la deviazione standard del campione del vettore.

__Nota:__ la funzione dovrà fare una cosa tipo __return v__ dove __v__ è una variabile di tipo __double *__ a cui abbiamo assegnato il valore restituito dalla __new__ in fase di allocazione del vettore.


## Esercizio 2
Generato un array di numeri casuali come nell'esercizio 1, calcorarne la media e la deviazione standard. Fatto questo avrete generato un vettore di numeri Gaussiani di dimensione __dim__:

1. Contare il numero __nout__ di elementi che distino dalla media del vettore più di due volte la deviazione standard del campione calcolate.

1. Allocare dinamicamente un altro array di dimensione __dim - nout__ e copiare al suo interno solo gli elementi che distino dalla media del vettore meno di 2 volte la deviazione standard calcolata. Stampare nel frattempo a video i valori eliminati.

1.  Cancellare il vettore originale.

1. Operare l'opportuno assengamento che renda il vettore "ripulito"  accessibile da ora in avanti con il "nome" del vecchio vettore (che è stato rimosso dallo heap). Per intenderci, se il vettore originale si usava come __v[i]__, da questo punto in avanti il vettore ripulito dovrà  esser usato come __v[i]__.


## Esercizio 3
1. Scrivere un programma che conti il numero di dati di tipo __int__  presenti nel file __"campione.dat"__ che si trova nella cartella __Laboratorio8__. Garantisco che il file contiene solo sequenze di caratteri separati da spazi, ciascuna correttamente codificante un intero.

1. Chiuda lo stream di input. Questo azzererà  lo stato dello stream.

1. Allochi dinamicamente un vettore di interi di dimensione pari al numero di dati interi scritti nel file.

1. Riapra lo stream di input associandolo allo stesso file __"campione.dat"__ e carichi tutti i dati nell'array allocato dinamicamente al punto precedente. Stampare a video il risultato, possibilmente usando campi di 10 caratteri (usando __setw__)
 e andando a capo ogni 5 interi.
 
 1. Registrare i dati contenuti nell'array nel file __"copiaCampione.dat"__, possibilmente formattando la stampa su file come quella a video (se avete capito gli stream non avrete dubbi su come procedere).
 
 
## Esercizio 4
Il file __"parametri.dat"__  contiene 3 dati numerici, uno intero e due "con la virgola". Il primo dato indica la numerosità  del campione di numeri Gaussiani che si desidera generare, il secondo dato la media della distribuzione Gaussiana da cui estrarli e il terzo la deviazione standard della stessa.

Letti questi dati, generare e salvare sul file __"campioneGauss.dat"__ il numero richiesto di dati Gaussiani estratti dalla popolazione indicata.
