#include <iostream>

using namespace std;

int main(int argc, char **argv){

	float a,b;

	cout << endl <<"Token/argomenti rilevati: " << argc << endl;

	for(int i=0; i<argc; i++){
		cout << endl << "Token " << i << ": " << argv[i];
	}
	cout << endl;

	a = atof(argv[1]);
	b = atof(argv[2]);
	
	//atoi

	cout << endl << "Somma: " << a+b << endl;

}