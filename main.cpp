#include "pelaaja.h"
#include "peli_loop_countdown.h"
#include <iostream>

using namespace std;

int main()
{
    int pelivalinta;
    string valinta;

    while(true)
    {
        cout << "Pelivalikko: \n\n1. Countdown\n2. Ei implementoitu\n\nValitse peli: "; cin >> pelivalinta;         //Pelivalikko ja input

        switch (pelivalinta)
        {
            case 1:
            {
                cout << "\n\nValitsit pelin Countdown\n\n";
                int pisteasetus;
                cout << "Anna pisteasetus, esim.(501): "; cin >> pisteasetus;         //Kysytään käyttäjältä alkupisteet, josta pelataan "countdown"
                Peli_loop_countdown peli = Peli_loop_countdown(pisteasetus);          //Luodaan peli olio
                break;
            }

            case 2:
            {
                cout << endl << "\nEI IMPLEMENTOITU\n" << endl;
                break;
            }

            default:
            {
                cout << "\nEi valintaa\n" << endl;
                break;
            }
        }
        cout << "Vaihda peliä (K/E): "; cin >> valinta;                                //Kysytään, halutaanko vaihtaa peliä, jos ei, lähdetään while loopista
        if(valinta == "K" || valinta == "k")
        {
            cout << "\n"; continue;
        }
        if(valinta == "E" || valinta == "e")
        {
            cout << "\n"; break;
        }
    }

    return 0;
}
