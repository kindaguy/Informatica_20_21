#Commento, inizia con un # e dura una riga

#Questa regola ha un target phony: esegui non e` il nome di un file
#e la regola non genera nulla, esegue solo l'azione
esegui:
	./esempioAD_cs.x

#compila e` anch'essa phony e  dipende dalla regola esempioAD_cs.x. Siccome compila non
#sara` (sperabilmente) il nome di un file nella cartella, esempioAD_cs.x verra`
#sempre richiamata
compila: esempioAD_cs.x



#regola normale: genera qualcosa (esempioAD_cs.x) e dipende dalle regole esempioAD_CS.o
# e libreria.o
  esempioAD_cs.x: esempioAD_cs.o libreria.o
	g++ esempioAD_cs.o libreria.o -o esempioAD_cs.x

#e cosi` via...
esempioAD_cs.o: esempioAD_cs.C libreria.h
	g++ -c esempioAD_cs.C

libreria.o: libreria.C libreria.h
	g++ -c libreria.C



