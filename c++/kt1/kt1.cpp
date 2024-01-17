#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int arvaus;
    srand(time(0));
    int random = rand() % 20 + 1;

    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> arvaus;
        if (arvaus > random) 
            std::cout << "Number is smaller." << std::endl;
        else if (arvaus < random) 
            std::cout << "Number is bigger." << std::endl;
        else if (arvaus == random) {
            std::cout << "Congratulations! You guessed the right number!" << std::endl;
            break;
        }
    }
    
    return 0;
}