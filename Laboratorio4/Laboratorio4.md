# Laboratorio 4: Generazione numeri casuali, uso funzioni e statistiche (minimali)

In questo laboratorio amplieremo il set di strumenti per la generazione di numeri casuali. Applicheremo quanto imparato per effettuare un'analisi statistica minimale di un campione casuale. Vedremo anche un primo esempio di ripulitura di un vettore dagli elementi "indesiderati".

## Esercizio 1
Scrivere un programma che, letto in ingresso un numero "razionale in singola precisione", salvi un un array di dimensione 10 "razionali in singola precisione" le potenze da zero a 9 del numero.

##
 
## Esercizio 2
Scrivere un programma che, avvalendosi di un array di interi di dimensione 20: 

1. Chieda all'utente quanti valori interi vuole inserire.
2. Controllato che il valore _n_ inserito dall'utente sia valido.
3. Legga gli interi inseriti dall'utente.
4. Conti e stampi a video il numero di valori negativi eventualmente presenti nel vettore. 
5.  Elimini dal vettore tutti gli elementi negativi presenti, preservando l'ordine dei dati inseriti.

#### Suggerimento 
Per eliminare un elemento negativo dall'array, basta spostare tutti quelli alla sua destra di una posizione verso sinistra.

[1 2 -3 4 5] &rightarrow; [1 2 4 5 5]

e registrare da qualche parte che il numero dei dati effettivamente presenti nell'array è diminuito di uno....

## Esercizio 3
Scrivere una funzione che, presi in ingresso due numeri interi positivi, restituisca 1 se il primo numero è multiplo intero dell'altro, zero altrimenti. Scrivere poi una variante della funzione in cui il valore retituito sia un valore booleano (__bool__).

## Esercizio 4
Scrivere una funzione che, presi in ingresso due numeri interi positivi _a_ e _b_ restituisca _a^b_ (leggere: _a_ elevato alla _b_)

## Esercizio 5
Nel PreLab abbiamo visto come generare numeri casuali interi nell'intervallo __[0,M]__. Scrivere:

1. Una funzione che, presi in ingresso due valori interi __min__ e __max__ generi un numero intero a caso nell'intervallo __[min,max]__.
1. Ricordando che il numero intero più grande restituito dalla funzione __rand()__ è  noto al compilatore come __RAND\_MAX__, scrivere una funzione che restutuisca un numero "razionale in doppia precisione" compreso nell'intervallo __[0,1]__ .
1. Scrivere una funzione che, presi in ingresso due valori "razionali in doppia precisione" __min__ e __max__, generi un numero a caso dello stesso tipo nell'intervallo __[min,max]__. 

#### Suggerimento: 

Dato un valore __x__ nell'intervallo __[0,1]__ posso ottenere un valore nell'intervallo __[a,b]__, a &lt;b, operando la seguente trasformazione affine:   __x*(b-a) + a__ . 

## Esercizio 6
Dichiarare e definire funzioni che, preso in ingresso un array di __double__ e il numero __n__ di dati registrati nell'array (garantito essere &leq; della dimensione dell'array) restituiscano:

1. la media dei dati
1. la varianza dei dati
1. il dato più piccolo
1. il dato più grande

 Usare quindi queste funzioni per determinare media, varianza, massimo e minimo di un vettore di 100  __double__ riempito con valori a caso nell'intervallo __[-3,3]__ .
 

### Nota: specifichiamo l'ovvio...ma per sicurezza ;-)
Ogni funzione andrà testata usando un programma che, da qualche parte, la richiami.
