#include "drehzahlueberwachung.h"


bool drehzahlueberwachung(int drehzahl) {
    
    if (drehzahl > MAX_DREHZAHL) {
        return 1; // Drehzahl zu hoch
    }
    return 0; // Drehzahl in Ordnung
}