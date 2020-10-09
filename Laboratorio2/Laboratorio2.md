# Laboratorio 2: Hello world, overflow, precisione, divisione euclidea

In questo laboratorio scriveremo alcuni semplici programmi in C++. Nella cartella dedicata al laboratorio troverete i codici sorgenti descritti nel PreLab2.

## Ricordate
- compilare: __g++ `<nomefilesorgente> ` -o `<nomefileeseguibile> `__
- eseguire:` ./<nomefileeseguibile> `

Niente spazi tra . e / e tra / e monefile
- convenzionalmente il file sorgente si indica con estensione .C oppure .cpp oppure .cxx. Questo consente, tra l'altro, anche a gedit di inferire la tipologia di contenuto del file e evidenziare la sintassi.

## Esercizio 0
Scrivete un programma che, letto in ingresso il vostro numero di matricola, stampi a video il messaggio

__Benvenuto `<matricola> `__

## Esercizio 1
1. Scrivere un programma che, letto da tastiera un numero intero, stampi a video il numero successivo e il numero precedente a quello fornito in ingresso.
1. Immettete come input il più grande e il più piccolo intero rappresentabile su 4 byte (32 bit). Osservate il risultato.

## Esercizio 2
1. Scrivere un programma che, registrato un valore letto in ingresso in una variabile di tipo __float__ stampi a video il numero letto incrementato di 0.1.
1. Immettere come input il valore 12345 e controllare il risultato.
1. Immettere come input il valore 123456 e controllare il risultato
1. immettere come input il valore massimo della mantissa di un __float__ e controllare il risultato.

## Esercizio 3
Scrivere il codice che implementa l'algoritmo di divisione euclidea con le seguenti specifiche:
1. Se anche solo uno degli operandi fosse negativo, il programma dovrà  stampare il messaggio: __Non funziono su numeri negativi__
1. Se il divisore è zero, il programma deve stampare: __Operazione non definita__
1. Altrimenti, il programma deve stampare il quoziente e il resto.

## Esercizio 4
Scrivete un programma che letta da tastiera una sequenza di numeri positivi terminata dal numero 0 ne calcoli e stampi a video:
1. La somma
1. La media aritmetica. 

A tal fine osserviamo che: 
- Servirà una variabile dove registrare il valore letto da tastiera
- Possiamo avvalerci di una variabile _contatore_, inizialmente avente valore 0, per contare il numero di dati immessi.
- Possiamo avvalerci un una variabile _accumulatore_, inizializzata a 0, per contenere la somma (parziale) dei valori immessi.
- Supponiamo che l'utente non inserisca numeri negativi, quindi non sarà necessario, per ora, controllare la positività dei valori immessi.
- Dovremo prestare attenzione alla terminazione della sequenza: dovremo sicuramente usare un ciclo, ma il primo dato letto da tastiera va letto prima di testare la condizione. Il dato successivo va letto prima di ritestare la condizione.
