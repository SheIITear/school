#include "Peli.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Peli::Peli(int enimmäisarvo) : maksimiLuku(enimmäisarvo), arvaustenMaara(0) {
    srand(std::time(0));
    satunnaisluku = (rand() % maksimiLuku) + 1;
}

int main() {
    Peli peli(100);

    peli.pelaa();

    return 0;
}

void Peli::pelaa() {
    bool pysySilmukassa = true;

    while (pysySilmukassa) {
        std::cout << "Anna arvauksesi välillä 1-" << maksimiLuku << std::endl;
        std::cin >> pelaajanArvaus;
        arvaustenMaara++;

        if (pelaajanArvaus == satunnaisluku) {
            std::cout << "Arvasit oikein! Numero = " << pelaajanArvaus << std::endl;
            pysySilmukassa = false;
            tulostaPelinTulos();
        } else if (pelaajanArvaus < satunnaisluku) {
            std::cout << "Arvauksesi on liian alhainen" << std::endl;
        } else {
            std::cout << "Arvauksesi on liian korkea" << std::endl;
        }
    }
}

void Peli::tulostaPelinTulos() const {
    std::cout << "Peli ohi. Arvausten määrä: " << arvaustenMaara << std::endl;
}