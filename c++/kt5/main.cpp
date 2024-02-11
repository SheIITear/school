#include <iostream>
#include <vector>

using namespace std;

class Asunto {
private:
    int asukkaat;
    int pintaAla;

public:
    Asunto(int asukkaat, int pintaAla) : asukkaat(asukkaat), pintaAla(pintaAla) {
        cout << "Asunto luotu" << endl; 
        cout << "Asunto maaritetty asukkaita=" << asukkaat << " nelioita=" << pintaAla << endl;
    }
};

class Kerros {
private:
    vector<Asunto> asunnot;

public:
    Kerros() {
        cout << "Kerros luotu" << endl;
    }
    void lisaaAsunto(const Asunto& asunto) {
        asunnot.push_back(asunto);
    }
};

class Katutaso : public Kerros {
public:
    Katutaso() : Kerros() {
        cout << "Katutaso luotu" << endl;
        lisaaAsunto(Asunto(2, 80)); 
        lisaaAsunto(Asunto(2, 80)); 
    }
};

class Kerrostalo {
private:
    Katutaso katutaso;
    vector<Kerros> kerrokset;

public:
    Kerrostalo() {
        cout << "Kerrostalo luotu" << endl;
    }
    void lisaaKerros(const Kerros& kerros) {
        kerrokset.push_back(kerros);
    }

    void lisaaKatutaso(const Katutaso& kTaso) {
        katutaso = kTaso;
    }
};

int main() {
    Asunto* as1 = new Asunto(2, 100);
    Asunto* as2 = new Asunto(2, 100);
    Asunto* as3 = new Asunto(2, 100);
    Asunto* as4 = new Asunto(2, 100);

    Kerros* eka = new Kerros();
    Kerros* toka = new Kerros();
    Kerros* kolmas = new Kerros();

    Katutaso* katutaso = new Katutaso();

    Kerrostalo* talo = new Kerrostalo();

    talo->lisaaKatutaso(*katutaso);

    talo->lisaaKerros(*eka);
    talo->lisaaKerros(*toka);
    talo->lisaaKerros(*kolmas);

    // Vapautetaan muistista olioita
    delete as1;
    delete as2;
    delete as3;
    delete as4;
    delete eka;
    delete toka;
    delete kolmas;
    delete katutaso;
    delete talo;

    return 0;
}