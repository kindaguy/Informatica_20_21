# Laboratorio 12: Esperienza Tavola di Galton, o diffusione 


Andiamo a scrivere codice che ci consenta di simulare e analizzare un cammino casuale (a passi discreti). Dividiamo logicamente il lavoro in 2 fasi: una generativa, dove produrremo la simulazione, e una di analisi. Per ciascuna fase produrremo un programma eseguibile.


## Esercizio 1 (Fase 1)

Scrivere una funzione

__int *generaTraiettoria(int length, int x0)__

che presi in ingresso il numero di posizioni (__length__) e la posizione iniziale (__x0__) generi una traiettoria di lunghezza __length__ secondo la regola

<img src="https://render.githubusercontent.com/render/math?math=X(0) = x_0, X(k + 1) = X_i(k) \pm Y_i^k">

dove 

<img src="https://render.githubusercontent.com/render/math?math=P(Y_i^k =+1) = P(Y_i^k =-1) =\frac{1}{2},\ \forall i,k">.

La funzione deve restituire l'indirizzo del vettore generato dinamicamente al suo interno. Notate che se voglio fare _N_ passi _length_ sarà _N+1_.

## Esercizio 2 (Fase 1)

Usando la funzione definita al punto precedente, generare un campione di traiettorie di dimensione indicata attraverso la funzione

__int **generaCamioneTraj(int ntraj,int length,int x0)__

che memorizzi il risultato in un vettore di traiettorie (matrice di interi) creato dinamicamente e ne restituisca l'indirizzo.

## Esercizio 3 (Fase 1)

Registrare la matrice generata al punto precedente in un file __traiettorie.dat__ scritto con il seguente formato:

1. Un intero: numero di traiettorie.
2. Un intero: lunghezza traiettoria. 
3. La matrice generata al punto precedente (possibilmente impaginata un po' bene).


## Intermezzo
Gli esercizi 1-3 devono dare luogo ad un programma dal nome __generaDati.C__, che generi il file indicato.

Cercate di controllare quanto fatto fino ad ora,  anche andando a visualizzare con RooT qualche traiettoria. Quando siete ragionevolmente sicuri della correttezza di quanto fatto fino ad ora, procedete oltre.

## Esercizio 4 (Fase 2)

Scrivere un programma che, una volta caricata la matrice delle traiettorie dal file __traiettorie.dat__, il cui formato è  noto (vedi sopra), faccia quanto segue:

1. Per ogni tempo _k_, calcolare la posizione media delle traiettorie e la varianza delle posizioni. Registrare le medie e le varianze al variare di _k_ in due vettori __vettMed__ e __vettVar__.

2. Introdotto un vettore di "tempi" __vettTime__ contenente i tempi k=0,1,2,...,NCalcolare e stampare a video i coefficienti di regressione  

3. Visualizzare a video lo scatterplot delle medie, delle varianze e delle rette di regressione determinate al punto precedente. Nota: se non siete capaci di mettere tutto sullo stesso grafico, cambiate di volta  in volta il codice perche' visualizzi almeno i punti e la retta di regressione una volta per la media e una volta per la varianza.

## Esercizio 5 (Fase 2)
Considerato che se una traiettoria è di lunghezza _N+1_, la posizione cadrà sicuramente nell'intervallo _(-N-1,N+1)_, disegnare l'istogramma al tempo finale (_N_), usando un numero "ragionevole" di bins.

## Conclusione e suggerimenti
Gli esercizi 4 e 5 prevedono la visualizzazione di grafici. Come sapete RooT blocca l'esecuzione quando comincia a disegnare, quindi potrebbe essere conveniente scrivere diversi programmi, tutti identici a meno della parte di RooT, che visualizza quello che ci interessa.

Da buoni fisici, chiedetevi quale modello potrebbe descrivere l'andamento della media e della varianza delle posizioni e cercate di confrontare l'evidenza "sperimentale" con quanto discusso a lezione.

Considerate che, per quanto semplice, questo esperimento modella fondamentali processi fisici, come appunto la diffusione di particelle. 
Quello che abbiamo simulato  è  un semplice processo di cammino casuale bilanciato, dove il camminatore scelgie di fare un passo a destra o a sinistra con uguale probabilità, per esempio lanciando una monetina bilanciata. Cosa succederebbe se la monetina fosse sbilanciata? Cosa cambierebbe: la posizione media o la varianza? Sarebbe ragionevole parlare di "deriva" (drift) del campione?
Se vorrete imbarcarvi in questo esperimento, avrete bisogno di

1. Modificare la funzione di generazione delle traiettorie passando la probabilità __pForw__ di fare un passo a sx.
2. Saper lanciare una monetina sbilanciata. A tal fine vi faccio osservare che se estraggo un numero (razionale) a caso A tra 0 e 1 e poi rispondo +1 se A è minore di __pForw__ e -1 altrimenti, quello che sto facendo è  proprio lanciare una monetina che mi fa andare avanti con probabilità __pForw__



## COMPITI PER LE VACANZE 

Nella cartella 

__/home/comune/InformaticaEsamiEsempi/ToDo_2020__

sulla macchina tolab.fisica.unimi.it, troverete una prova scritta e una prova di laboratorio con i relativi dati. Provate a svolgerle, considerando che il tempo a disposizione per il completamento di ciascuna prova è di 2 ore. 
Ricordatevi che la prova di laboratorio dovrà essere copiata su __tolab__, quindi esercitatevi con il comando __scp__ (che vi serve anche per copiare i files dal laboratorio!) e __ssh__.

__Il giorno 8 gennaio 2021 a partire dalle ore 8:30 svolgeremo insieme entrambe le prove. Si tratta di un incontro facoltativo. Al termine dello svolgimento delle prove io, Andrea e Riccardo saremo a disposizione per un "ricevimento aperto", sempre in Aula C.__