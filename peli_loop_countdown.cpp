#include "peli_loop_countdown.h"
#include "pelaaja.h"
#include "tallentaja.h"
#include <iostream>
#include <vector>

using namespace std;

int Pelaajan_toiminnot(Pelaaja& x) //Lasketaan pelaajan heittotulosten pisteet
{
    int heittotulos;
    cout << "\nHeittovuorossa: "; x.tulostanimi();
    cout << "Pisteet: " << x.getpisteet() << "\nHeittojen summa: "; cin >> heittotulos;
    if(heittotulos > 180 || heittotulos > x.getpisteet())
    {
        cout << "\nEi hyväksytty.\n";
        return 0;
    }
    x.laskepisteet_countdown(heittotulos);
    if(x.getpisteet() == 0)
    {
        cout << "Voittaja on "; x.tulostanimi();
        return 1;
    }
    else
    {
        return 0;
    }
}

int pelaajien_maara() //Annetaan kelvollinen pelaajamäärä
{
    int x;
    cout << "Anna pelaajien määrä (1-6): "; cin >> x;
    if(x <= 6 && x >= 1)
    {
        cout << "\n";
        return x;
    }
    else
    {
        cout << "\nEi kelvollinen määrä, asetettiin oletuksena 1.\n";
        return 1;
    }
}

Peli_loop_countdown::Peli_loop_countdown(int pisteasetus) : Tallentaja("Countdown")
{  
    vector<Pelaaja> pelaajat;                                   //Luodaan "pelaajat" merkkijonolista
    int pelaajamaara = pelaajien_maara();                       //pelaajamäärän asetus

    for(int i = 0; pelaajamaara > i; i++)                       //Pelaajien alustus
    {
        string nimi;
        cout << "Anna " << i+1 << ". pelaajan nimi: "; cin >> nimi;
        pelaajat.push_back(Pelaaja(pisteasetus,nimi));          //Tallennetaan pelaaja olion merkkijonolistaan vector funktiolla
        tallennapelaaja(nimi,i+1,pisteasetus);                  //Tallennetaan pelaaja "Tallenna" olion ottelun_tiedot listaan
    }
    while(true)                                                 //revanssiluuppi käydään niin kauan kuin pelaaja haluaa
    {
        this->kierroscount = 0;
        while(wincondition == 0)                                //ottelun kiertoluuppi. Wincondition vaihtuu -> true, jos jonkun pelaajan pistearvo == 0
        {
            this->kierroscount++;
            for(int i=0; pelaajamaara > i; i++)                 //for loopissa käydään kaikki annetut pelaajat läpi ja annetaan pelaajan "id" parametrina Pelaajan_toiminnot funktiolle
            {
                this->wincondition = Pelaajan_toiminnot(pelaajat[i]);
                tallennapist(i+1, pelaajat[i].getpisteet());    //Tallennetaan pelaajan kyseisen kierroksen pistetilanne Tallentaja olion ottelun_tiedot listaan
                if(wincondition == 1)
                {
                    break;
                }
            }
        }                                                        //ottelun kiero päättyy

        cout << "\n";
        tulosta_ottelu(pelaajamaara);                            //Tulostetaan ottelun statistiikat

        string valinta;
        this->wincondition = 0;                                  //Alustetaan wincondition

        cout << "\nPelaa uudestaan (K/E): "; cin >> valinta;      //kysytään käyttäjälätä haluaako pelata uudestaan
        if(valinta == "K" || valinta == "k")                      //jos kyllä -> alustetaan pelaajien pisteet ja revanssilooppi jatkuu
        {                                                         //jos ei -> lähdetään revanssiloopista
            cout << "\nAloitetaan...\n";
            for(int i=0; pelaajamaara > i; i++)
            {
                pelaajat[i].setpisteet(pisteasetus);
            }
        }
        if(valinta == "E" || valinta == "e")
        {
            cout << "\n";
            break;
        }
    }
}
