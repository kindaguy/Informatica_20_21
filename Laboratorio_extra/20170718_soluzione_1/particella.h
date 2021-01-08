#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>

#define RECT_MAX_X 1.f
#define RECT_MAX_Y 0.5f
#define DELTAT 1.5f

using namespace std;

struct particella{
    float x;
    float y;
    float vx;
    float vy;
};


//Specializzazione stampa per struttura particella
void stampaPart(particella part);
void stampaPartFile(ofstream *os, particella part);

//Specializzazione lettura (da file) per particella
void leggiPartFile(ifstream *is, particella * pPart);

//Test dentro/fuori (specifico)
bool isout(particella part);

//Utility
void swapPart(particella *p1, particella *p2);

//Evoluzione particella
void evolvi(particella *vett, float dt);

   
