#ifndef PELAAJA_H
#define PELAAJA_H

#include<iostream>

using namespace std;

class Pelaaja
{
private:
    string nimi;
    int pisteet;
    int edell_pist;
    int pelaajamaara;

public:
    Pelaaja(int pts, string nimi_in);

    int getpisteet();
    void laskepisteet_countdown(int tulos);
    void tulostanimi();
    void setpisteet(int n);
};

#endif // PELAAJA_H
