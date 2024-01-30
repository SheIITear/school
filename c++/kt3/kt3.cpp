#include <iostream>

class Chef {
    public:
        Chef(std::string x) : name(x) {
            std::cout << "Chef " << name << " konstruktori" << std::endl;
        };

        ~Chef() {
            std::cout << "Chef " << name << " destruktori" << std::endl;
        };

        void makeSalad() {
            std::cout << "Chef " << name << " makes salad" << std::endl;
        };

        void makeSoup() {
            std::cout << "Chef " << name << " makes soup" << std::endl;
        };

    protected:
        std::string name;
};

class ItalianChef : public Chef {
    public:
        ItalianChef(std::string x, int y, int z) : Chef(x) {
            this->jauhot = y;
            this->vesi = z;
        };

        ~ItalianChef() {
            std::cout << "Chef " << name << " destruktori" << std::endl;
        };

        void makePasta(int x, int y) {
            std::cout << "Chef " << name << " makes pasta with special recipe (snaps the spaghetti in half)" << std::endl;
            std::cout << "Chef " << name << " uses jauhot = " << x << std::endl;
            std::cout << "Chef " << name << " uses vesi = " << y << std::endl; 
            this->jauhot = this->jauhot - x;
            this->vesi = this->vesi - y;
        };

        std::string getName() {
            return name;
        };

    private:
        int jauhot;
        int vesi;
};

int main() {
    Chef kokki("Gordon Ramsay");
    kokki.makeSalad();
    kokki.makeSoup();

    ItalianChef kokki2("Anthony Bourdain", 250, 100);
    kokki2.makePasta(250, 100);
    return 0;
}
