#ifndef PELI_H
#define PELI_H
#include <iostream>

using namespace std;

class Peli {
private:
    int maksimiLuku;
    int pelaajanArvaus;
    int satunnaisluku;
    int arvaustenMaara;

    void tulostaPelinTulos() const;

public:
    Peli(int enimmäisarvo);
    void pelaa();
};

#endif