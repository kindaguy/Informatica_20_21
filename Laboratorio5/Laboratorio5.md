# Laboratorio 5: Trasformazione di Box-Muller e metodi Monte Carlo

In questo laboratorio completeremo il nostro kit per la generazione di numeri a caso aggiungendo la generazione di  numeri casuali "Gaussiani". Procederemo quindi con l'applicazione di tecniche Monte Carlo per la stima di _pigreco_ e di un integrale. Per far questo ci avvarremo anche della libreria __cmath__, capace di calcolare diverse funzioni trigonometriche e altro....

## Esercizio 1
Implementare una funzione che realizzi la trasformazione di Box-Muller descritta a lezione. In particolare, la funzione dovrà ricevere in ingresso due parametri __double__ corrispondenti alla media e alla deviazione standard (radice quadrata della varianza) della distribuzione Gaussiana da cui vogliamo estrarre valori, e restituire un singolo valore __double__ corrispondente al primo valore (__Z0__) generato dalla trasformazione. Pertanto la signature della funzione sarà

__double  boxmuller(double m,double s)__

Una volta inclusa la libresia __cmath__ è possibile calcolare il logaritmo naturale, il seno, coseno e la radice quadrata di un numero __x__ rispettivamente attraverso

__log(x)__ __sin(x)__ __cos(x)__ __sqrt(x)__

Gli argomenti delle funzioni seno e del coseno si intendono in radianti. I parametri di ingresso sono __double__ (o convertriti a tali) così come i valori di ritorno.
 
## Esercizio 2
Scrivere un programma che, dichiarato un vettore di 1000 __double__ :
 1. lo riempia di valori a caso estratti da una Gaussiana di media _m_ e deviazione standard _s_ (chiesti in ingresso all'utente).
2. Calcoli e stampi a video la media e la deviazione standard del vettore usando le funzioni già implementate negli scorsi laboratori.
3. Conti il numero di valori che distano dalla media teorica _m_ più di _k_ volte la deviazione standard _s_ teorica, ovvero tali che |x[i]-m|>k*s per k=1,2,3. NOTA: Le sbarrette indicano il valore assoluto, calcolabile con la funzione __fabs(x)__ inclusa nella libreria __cmath__.


## Esercizio 3
Stimiamo _pigreco_ usando la tecnica Monte Carlo discussa a lezione. Supporremo che la circonferenza _A_ abbia centro nel punto O=(0,0) e raggio unitario. I punti verranno invece sparati a caso nel quadrato _E_ di lato 2 anch'esso con centro (punto di intersezione delle diagonali) nell'origine.  Struttureremo la soluzione come segue:

1. Definire una funzione

__int withincircle(double x, double y)__

 che, presa in ingresso una coppia di valori __double__ (la coordinata x e y rispettivamente di un punto estratto a caso in _E_) restituisca 1 se il punto corrispondente cade all'interno di una circonferenza di raggio unitario centrata nell'origine.

2. Definire una funzione 

__int countwithin(int n)__

che, preso in ingresso un valore intero _n_, estragga _n_ punti a caso nel quadrato di lato 2 e centro nell'origine, e restituisca il numero di punti che cadono all'interno di una circonferenza di raggio unitario e centro nell'origine. A tal fine, la funzione dovrà usare la funzione __withincircle__ definita al punto precedente.

3. Definire una funzione

__double singlemeasure(int n)__

che preso in ingresso il numero di punti a caso da utilizzare, fornisca una misura di _pigreco_ usando la relazione vista a lezione. 

4. Fatto questo, scrivere un programma che fornisca una stima di _pigreco_ attraverso M=50 misure, ciascuna delle quali usa 100 punti estratti a caso. Il programma dovrà quindi calcolare la media e la varianza del campione del vettore di misure. La media del campione sarà  la nostra stima di _pigreco_, la varianza invece una misura della qualità  delle misure. Cosa succede alla varianza se invece di 100 punti usassimo 200,300,400,500  punti per ogni misura?


## Esercizio 4
Fornire una stima Monte Carlo dell'integrale

 ![](integrale.jpeg)
 
 usando M=20 _misure_ ciscuna delle quali usa _k=50_ punti estratti a caso nell'intervallo [0,2]. Calcolare la stima dell'integrale (media delle _M_ misure) e la deviazione standard del campione delle misure. Cosa succede se usiamo _k=100,150,200_ punti per ogni misura? 