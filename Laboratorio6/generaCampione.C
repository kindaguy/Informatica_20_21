#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(){
    ofstream uscita;

    uscita.open("campione.dat");

    for(int i=0; i<50; i++){
        if(i%10==0) uscita << endl;

        uscita <<setw(10)<<rand()%100;
        
    }

    uscita.close();
    return 0;
}
