Sequenza dei comandi da eseguire:


g++ -c esempioAD_cs.C
g++ -c libreria.C
g++ libreria.o esempioAD_cs.o -o esempioAD_cs.x

Assumendo che non ci siano errori di sintassi:

-Il primo comando genera esempioAD_cs.o, ovvero il file oggetto contenente la descrizione dei record di attivazione in esempioAD_cs.C, tra cui anche il main.

-Il secondo comando genera libreria.o, ovvero il file contenente la descrizione dei record di attivazione delle funzioni definite in libreria.C

-Il terzo comando invoca il LINKER, che mette insieme tutti i record di attivazione e genera un file contenente il codice eseguibile. L'opzione -o consente di decidere il nome del fine contenente il risultato dell'operazione, nel nostro caso 

esempioAD_cs.x

Se non specificato attraverso l'opzione -o il nome di default del file eseguibile e` a.out...
