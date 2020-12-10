# Laboratorio 10:  make, arrayT e ricerca per bisezione

Continuiamo il processo di riorganizzazione del materiale prodotto fino ad oggi in modo strutturato, attraverso la creazione di liberie, e a velocizzare il processo di compilazione attraverso il comando __make__ e al relativo __makefile__.

Esemplifichiamo l'uso della struttura __arrayT__.

Sposteremo poi la nostra attenzione  sulla soluzione di problemi algoritmicamente più complessi, e alla codifica delle relative soluzioni.

## Esercizio 1 

Consideriamo a libreria creata seguendo le istruzioni dell'esercizio 2 della settimana 9, ovvero la coppia file header-file sorgente, che qui chiameremo rispettivamente __statistica.h__ e __statistica.C__ .


Prendiamo ancheil file, diciamo __programma.C__, che definisce il __main___ e che includa __statistica.h__ (oltre ad eventuali altre librerie necessarie al funzionamento del __main__) che usi funzionalità della libreria __statistica__.

Procedere alla compilazione separata di __statistica.C__ e __programma.C__,  e poi "collegare" i due file oggetto nel file __programma.x__.

Fatto questo, preparare un, sulla falsa riga di quanto a disposizione  nella cartella __CompSepMake__ e illustrato anche nel file __make_README.txt__, un  __makefile__ che consenta di compilare ed eseguire il programma attraverso i comandi

__make compila__

__make esegui__


## Esercizio 2

Scrivere un programa che chieda all'utente il nome di un file contenente una sequenza di interi (di lunghezza ignota) e ne carichi il contenuto attraverso una funzione

__arrayInt caricaArrayIntFile(char * nomefile)__

che preso in ingresso il nome di un file, ne carichi il contenuto attraverso un  __arrayInt__ (la struct discussa oggi a lezione) e restituisca la struct inizializzata. In caso di errore, la funzione dovrà assegnare al campo __int *raw__ dell'__arrayInt__ il valore __NULL__ e al campo __int size__ il valore -1.

Ricordiamo:

1. Che l'assegnamento tra struct dello stesso tipo è possibile.
1. Che il campo __int *raw__ della struttura __arrayInt__ contiene l'indirizzo del vettore dinamicamente allocato (e caricato) dalla funzione __caricaArrayIntFile__, che quindi sopravviverà alla chiusura della funzione.

Scrivere poi una variante della funzione con signature

__void  caricaArrayIntFile(char * nomefile, arrayInt * pa)__

che faccia le stesse cose su una variabile di tipo arrayInt passata alla procedura per riferimento.

## Esercizio 3

Scrivere una funzione

__bool is_palindrome(char *stringa)__

che, preso in ingresso un array di caratteri contenente una parola di __nchars__ caratterri, determini la palindromia o meno della parola passata. Ricordiamo che una parola è  palindroma se si legge nello stesso modo da sinistra verso destra e da destra verso sinistra.

Per far questo sarà necessario determinare il numero di caratteri della stringa passata: ricordate che la stringa è terminata dal carattere speciale '\0' (occhio a usare le virgolette giuste), e sarete quindi in grado di determinare da soli la il numero di caratteri che compongono la parola inserita.

## Esercizio 4

Si carichino gli interi descritti nel file __datiInteri.dat__ in un vettore di lunghezza opportuna. I dati descritti sul file sono ordinati, quindi il vettore caricato sarà anch'esso (sperabilmente) ordinato.

Implementare la funzione 

__int ricercaBinaria(int *v, int key,  int beg, int end)__

discussa a lezione e testarla.

