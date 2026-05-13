#include <iostream>
#include "drehzahlueberwachung.h"

int main() {
    int drehzahl = 0; // Beispielwert für Drehzahl
    int ErrorCounter = 0; // Zähler für Fehler

    for (int i = 0; i < 20; ++i) {
         drehzahl += 500; // Erhöhe die Drehzahl in jedem Schritt
         std::cout << "Aktuelle Drehzahl: " << drehzahl << std::endl;
         if (drehzahlueberwachung(drehzahl)) {
             if (drehzahl > MAX_DREHZAHL) {
                std::cout << "FAILED: Ueberwachung defekt, Drehzahl zu hoch!" << std::endl;
                 ErrorCounter++; // Fehlerzähler erhöhen, wenn die Drehzahl zu hoch ist
             }
             else {
                std::cout << "OK: Drehzahlueberwachung in Ordnung." << std::endl;
             }
         } else {
            if (drehzahl <= MAX_DREHZAHL) {
                std::cout << "FAILED: Ueberwachung defekt, Drehzahl ist i.O.!" << std::endl;
                ErrorCounter++; // Fehlerzähler erhöhen, wenn die Drehzahl zu niedrig ist
            }
            else {
                std::cout << "OK: Drehzahlueberwachung in Ordnung." << std::endl;
            }
            
         }
    }
    std::cout << "Anzahl der Fehler: " << ErrorCounter << std::endl;
    if (ErrorCounter > 0) {
        std::cout << "Es gab Fehler bei der Drehzahlüberwachung." << std::endl;
        return 1; // Fehlercode zurückgeben
    } else {
        std::cout << "Alle Drehzahlen waren in Ordnung." << std::endl;
        return 0; // Erfolgscode zurückgeben
    }
}

