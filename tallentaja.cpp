#include "tallentaja.h"
#include <iomanip>
#include <iostream>

using namespace std;

Tallentaja::Tallentaja(string n)
{
    Tallentaja::alustatallentaja(n);
}

void Tallentaja::alustatallentaja(string pelin_nimi) //Alustetaan ottelun_tiedot lista
{
    this->kierroscount = 0;
    this->ottelun_tiedot[0][0] = pelin_nimi;    //Ensimmäiseen ottelun_tiedot listan tietopaikkaan tulee pelin nimi

    for(int i = 0; 7 > i; i++)
    {
        for(int n = 1; 50 > n; n++)
        {
            this->ottelun_tiedot[n][i] = "\0";  //Loput paikat täytetään NULLeina
        }
    }
}

void Tallentaja::tallennapelaaja(string nimi, int pelaajanro, int pist) //luodaan ottelun_tiedot -listan ensimmäiselle ja toiselle riville pelaajatiedot
{
    this->ottelun_tiedot[0][pelaajanro] = nimi;
    string pist_str = to_string(pist);
    this->ottelun_tiedot[1][pelaajanro] = pist_str;
}

void Tallentaja::tallennapist(int pelaaja_nro, int pist) //tallennetaan pelaajan kierroksen n pisteet ottelun_tiedot listaan
{
    string pist_str = to_string(pist);                  //Muunnetaan integerit stringeiksi
    string kierros_str = to_string(kierroscount);

    this->ottelun_tiedot[kierroscount+1][0] = kierros_str;          //Kierrosluku tulee listassa aina rivin ensimmäiselle paikalle
    this->ottelun_tiedot[kierroscount+1][pelaaja_nro] = pist_str;   //Pelaajan pistemäärä tulee pelaajan nimen alle, eli pelaajan numeron osoittamalle kohdalle rivillä
}

void Tallentaja::tulosta_ottelu(int pelaajamaara) //Tulosta ottelun tiedot
{
    for(int i = 0; pelaajamaara+1 > i; i++)     //Ensimmäinen rivi tulostetaan erikseen.
        {
            cout << setw(15);                   //asetetaan vakio välitys tulosteille
            cout << ottelun_tiedot[0][i];
        }

        cout << "\n";

    for(int i = 0; pelaajamaara+1 > i; i++)     //Tehdään toiselle riville sama kuin ensimmäiselle
        {
            cout << setw(15);
            cout << ottelun_tiedot[1][i];
        }

        cout << "\n";

        for(int i = 2; 51 > i; i++)             //Tulostetaan loput listasta riviltä 3 lähtien
        {
            if(ottelun_tiedot[i][0].empty())
            {
                break;
            }
            for(int n = 0; pelaajamaara+1 > n; n++)
            {
                cout << setw(15);
                cout << ottelun_tiedot[i][n];
                if(n == pelaajamaara)
                {
                    cout << "\n";               //Aina rivin jälkeen rivinvaihto
                }
            }
        }
}
