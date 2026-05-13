#include "highflow.h"


int highflow (int rpm) {
    
    if (rpm < rpm_LL) {     // Wenn die Drehzahl unter der unteren Grenze liegt, bleibt das ventil geschlossen (0% Durchfluss)
        return 0; 
    }
    if (rpm > rpm_UL) {    // Wenn die Drehzahl über der oberen Grenze liegt, bleibt das ventil vollständig geöffnet (100% Durchfluss)
        return 100; 
    }
    return (rpm - rpm_LL) * 100 / (rpm_UL - rpm_LL); // Berechnung der Durchflussrate in Prozent    
}
