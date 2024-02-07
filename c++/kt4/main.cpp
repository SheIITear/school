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

    Katutaso katutaso;
    Kerrostalo talo;

    talo.lisaaKatutaso(katutaso);

    Kerros kerros1, kerros2, kerros3;
    for (int i = 0; i < 4; ++i) {
        kerros1.lisaaAsunto(Asunto(2, 100)); 
        kerros2.lisaaAsunto(Asunto(2, 100));
        kerros3.lisaaAsunto(Asunto(2, 100));
    }
    talo.lisaaKerros(kerros1);
    talo.lisaaKerros(kerros2);
    talo.lisaaKerros(kerros3);
    return 0;
}
