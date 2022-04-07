#ifndef TALLENTAJA_H
#define TALLENTAJA_H
#include <iostream>

using namespace std;

class Tallentaja //Tallentaja on pelimuoto olioiden (Countdown) parent
{
protected:
    int kierroscount = 0;
    string ottelun_tiedot[51][7];

    Tallentaja(string);

    void alustatallentaja(string);
    void tulosta_ottelu(int);
    void tallennapist(int, int);
    void tallennapelaaja(string, int, int);
};

#endif // TALLENTAJA_H
