#include "highflow.h"


int highflow (int rpm) {
    
    if (rpm < rpm_LL) {
        return 0; // Durchflussrate zu hoch
    }
    if (rpm > rpm_UL) {
        return 100; // Durchflussrate zu hoch
    }
    return (rpm - rpm_LL) * 100 / (rpm_UL - rpm_LL); // Berechnung der Durchflussrate in Prozent    
}