Uso del comando make.

NOTA: anche questo e` un file di istruzioni che non si compila.

make e` un programma. Viene installato di default in linux, su altri SO non so.

Cosa fa make? 

Legge un file dal nome makefile (o Makefile, no estensioni), contenente delle
istruzioni scritte secondo certe regole.

E` uno strumento di comodita` estrema (direi quasi indispensabile, per chi
scrive codice sul serio), specialmente quando si tratta di compilare 
programmi che fanno uso di librerie.

Una spiegazione esaustiva del funzionamento del make richiederebbe un corso
a parte. Qui mi limito a specificare le poche cose che servono a noi.

Il makefile si compone di una serie di punti di ingresso (regole) ciascuna
con un nome. Ogni regola specifica un target e ha delle dipendenze 
(altri target o nomi di file) e specifica un'azione da compiere.

target: dipendenze...
    azione

Notate che:

-il blocco che inizia con target e finisce con l'azione definisce la regola.

-dopo il nome del target ci vanno i ":" 

-dipendenze: e` un elenco di nomi di file o target, separati da SPAZI

-prima di "azione" c'e` dello spazio (singola tabulazione): NON e` accessorio,
fa parte della sintassi quindi mettetelo.

-azione specifica il comando da eseguire.

Esempio:

libreria.o: libreria.h libreria.C
    g++ -c libreria.C


Quindi: 

-il nome del target e` libreria.o
-le dipendenze sono libreria.h e libreria.C: questi sono i nomi dei files
che sono coinvolti, a qualche livello, nell'azione.
-azione: compila (senza tentare di linkare) libreria.C

Quando il make legge le dipendenze cotrolla se queste corrispondono al 
target di altre regole definite da qualche parte nel makefile. Se si, prima di
procedere  esegue le regole associate al target; se no...li interpreta come
nomi di file.

Ora: se il target ha un'estensione .o, il make capisce che la regola serve per 
generare un file oggetto (.o). A questo punto se nelle dipendenze compaiono dei nomi di file, controlla se il target esiste gia`. Se si verifica se i files sono stati modificati dopo il target (.o): se si allora rigenera il target. Se no, non fa nulla. 

Un altro esempio di target, simile a quello sopra e`

prog.o: prog.C libreria.h
    g++ -c prog.C

Ci possono essere target che non sono .o:

prog.x: libreria.o prog.o
    g++ libreria.o prog.o -o prog.x

In questo caso il make contolla se libreria.o e prog.o sono target definiti
sotto, se si li esegue e poi passa a eseguire l'azione (comando di linking).
Ovviamente, perche' il tutto funzioni, la regola compila DEVE essere messa
prima delle regole in dipendenza (libreria.o e prog.o).

Quindi il makefile sara` fatto come (vedi makefile nella cartella...)

Possiamo anche definire target che non sono nomi di file. In questo caso 
vengono comunemente definiti target "phony".

Ad esempio potremmo definire il target

compila: prog.x

(non mi sono dimenticato l'azione: non c'e`). Chiaramente, scrivendo quesa
regola prima della regola prog.x, quando chiameremo il make sulla regola
"compila" il make vedra` la dipendenza da prog.x e la eseguira`.

Per fare eseguire al make una regola, e a cascata tutte le regole nelle
dipendenze, basta scrivere, da riga di comando,

make nomeregola

Per esempio

make libreria.o 

eseguira` la regola libreria.o, generando libreria.o, mentre

make prog.x 

o

make compila

porteranno alla generazione del codice eseguibile.

Un esempio di makefile completo e` disponibile nella cartella.

