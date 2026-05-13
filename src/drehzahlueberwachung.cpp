#include "drehzahlueberwachung.h"


bool drehzahlueberwachung(int drehzahl) {
    
    if (drehzahl > MAX_DREHZAHL) {
        return 0; // Drehzahl zu hoch
    }
    return 1; // Drehzahl in Ordnung
}