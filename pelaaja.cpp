#include "pelaaja.h"
#include <iostream>

using namespace std;

Pelaaja::Pelaaja(int pts, string nimi_in) //Luodaan pelaaja antamalla sille pisteet ja nimi
{
    this->nimi = nimi_in;
    this->pisteet = pts;
}

int Pelaaja::getpisteet()
{
    return pisteet;
}

void Pelaaja::tulostanimi()
{
    cout << nimi << ".\n";
}

void Pelaaja::setpisteet(int n)
{
    this->pisteet = n;
}

void Pelaaja::laskepisteet_countdown(int n)
{
     cout << "\n";
     this->pisteet = pisteet - n;
}

