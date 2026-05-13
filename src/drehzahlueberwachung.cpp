


bool drehzahlueberwachung(int drehzahl) {
    const int MAX_DREHZAHL = 5000; // Beispielwert für maximale Drehzahl
    if (drehzahl > MAX_DREHZAHL) {
        return false; // Drehzahl zu hoch
    }
    return true; // Drehzahl in Ordnung
}