#include "highflow.h"
#include <iostream>

int main() {
    int rpm = 0; // Beispielwert für Drehzahl
    int ErrorCounter = 0; // Zähler für Fehler
    int testcounter = 20; // Zähler für Tests

    for (int i = 0; i < testcounter; ++i) {
         rpm += 200; // Erhöhe die Drehzahl in jedem Schritt
         std::cout << "Aktuelle Drehzahl: " << rpm << std::endl;
         int gauge_position = highflow(rpm);
         std::cout << "gauge_position: " << gauge_position << "%" << std::endl;
         if (gauge_position == 0 && rpm >= rpm_LL || gauge_position != 100 && rpm >= rpm_UL) {
             std::cout << "FAILED: gauge_position zu niedrig, aber Drehzahl ist über dem unteren Grenzwert!" << std::endl;
             ErrorCounter++; // Fehlerzähler erhöhen, wenn die gauge_position zu hoch ist
         }
         else if (gauge_position == 100 && rpm < rpm_UL || gauge_position != 0 && rpm < rpm_LL) {
             std::cout << "FAILED: gauge_position zu hoch, aber Drehzahl ist unter dem oberen Grenzwert!" << std::endl;
             ErrorCounter++; // Fehlerzähler erhöhen, wenn die gauge_position zu niedrig ist
         }
         else {
             std::cout << "OK: gauge_position in Ordnung." << std::endl;
         }
    }
    std::cout <<"TESTS: " << testcounter << " FAILED: " << ErrorCounter << std::endl;
    if (ErrorCounter > 0) {
        std::cout << "Es gab Fehler bei der Durchflussüberwachung." << std::endl;
        return 1; // Fehlercode zurückgeben
    } else {
        std::cout << "Alle gauge_positionn waren in Ordnung." << std::endl;
        return 0; // Erfolgscode zurückgeben
    }
}