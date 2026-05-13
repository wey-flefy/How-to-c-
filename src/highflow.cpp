#include "highflow.h"


int highflow (int rpm) {
    
    if (rpm < rpm_LL) {
        return 0; 
    }
    if (rpm > rpm_UL) {
        return 100; 
    }
    return (rpm - rpm_LL) * 100 / (rpm_UL - rpm_LL); // Berechnung der Durchflussrate in Prozent    
}
