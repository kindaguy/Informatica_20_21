#Makefile esemplificante i comandi di compilazione di file contenenti
#codice RooT


#NOTA: definizione di variabili in un makefile
#Qui sotto definiamo le variabili CFLAGS e LIBS.
#Io ho usato nomi con lettere maiuscole, ma potete usare 
#i nomi le lettere che volete.

CFLAGS = `root-config --cflags`
LIBS = `root-config --libs`

#Per usare le variabili la sintassi e`:
#    $(NOMEVARIABILE)
#In questo modo il contenuto della variabile viene usato.

#Non fate confusione con le variabili del linguaggio C++:
#le variabili in un makefile contengono tipicamente stringhe, che 
#vengono "espanse" al posto di $(NOMEVARIABILE).


provaHisto.x: provaHisto.C
	g++ provaHisto.C -o provaHisto.x  $(CFLAGS) $(LIBS)

#e` equivalente a....
#provaHisto.x: provaHisto.C
#	g++ provaHisto.C -o provaHisto.x `root-config --cflags` `root-config --libs`

