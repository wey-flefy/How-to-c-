#include <iostream>
#include "inc/drehzahlueberwachung.h"

int main() {
    int drehzahl = 4500; // Beispielwert für Drehzahl
    if (drehzahlueberwachung(drehzahl)) {
        std::cout << "Drehzahl in Ordnung." << std::endl;
    } else {
        std::cout << "Drehzahl zu hoch!" << std::endl;
    }
    return 0;
}