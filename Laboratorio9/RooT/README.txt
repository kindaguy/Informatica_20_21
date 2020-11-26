Per compilare un file sorgente che usi la libreria RooT, e` necessario passare dei "flag" di compliazione ulteriori.

`root-config --cflags`
`root-config --libs`

che vanno messi dopo il noto comando di compilazione.

Per compilare il file esempioScatter.C, per esempio, devo scrivere:

g++ esempioScatter.C -o esempioScatter.x `root-config --cflags` `root-config --libs`

In caso voleste generare solo il file oggetto dovreste scrivere:

g++ -c esempioScatter.C  `root-config --cflags` `root-config --libs`

