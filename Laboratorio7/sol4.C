#include <iostream>
#include <iomanip>

#define NN 4
#define MM 3


using namespace std;

int main(){

    //Dichiaro la matrice e la matrice trasposta
    int A[NN][MM];
    int AT[MM][NN];


    //Carico la matrice
    for(int i=0; i< NN; i++){//Per ogni riga di A
        for(int j=0; j< MM; j++){//Per ogni elemento della riga
            A[i][j]  = i * MM *sizeof(int)+j*sizeof(int);
        }
    }

    //Stampo la matrice
    cout << endl << "Matrice A: " << endl;
    for(int i=0; i< NN; i++){//Per ogni riga di A
        cout << endl;
        for(int j=0; j<MM; j++){//Per ogni elemento della riga
            cout << setw(10) << A[i][j];
        }
    }

    cout << endl;

    //Calcolo la matrice trasposta

    for(int i=0; i< NN; i++){//Per ogni riga di A
        for(int j=0; j< MM; j++){//Per ogni elemento della riga
            AT[j][i]  = A[i][j];
        }
    }

 //Stampo la matrice
    
    cout << endl << "Matrice AT: " << endl;
    for(int i=0; i< MM; i++){//Per ogni riga di A
        cout << endl;
        for(int j=0; j<NN; j++){//Per ogni elemento della riga
            cout << setw(10) << AT[i][j];
        }
    }





    return 0;

}
