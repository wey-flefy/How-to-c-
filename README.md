# CI-CD_Test

Ein C++-Projekt zur automatischen Prüfung einer Drehzahlüberwachung für Autosteuergeräte. Das Hauptprogramm nimmt externe Drehzahlwerte als Eingabe und prüft diese gegen einen Grenzwert. Integrationstests validieren die korrekte Funktionalität mit verschiedenen Eingabewerten.

## Funktionalität

- **Drehzahlüberwachung**: CLI-Tool, das einen Drehzahlwert als Kommandozeilenargument nimmt und prüft, ob dieser den Grenzwert von 70 überschreitet
- **Integrationstests**: Automatisierte Tests, die das Hauptprogramm mit 11 verschiedenen Werten (0-100) aufrufen und die Exit-Codes validieren
- **CI/CD**: GitHub Actions führt automatisch Builds und Tests bei Push/PR aus

## Projektstruktur

```
CI-CD_Test/
├── CMakeLists.txt                    # Build-Konfiguration
├── main.cpp                          # ???
├── inc                               # header files
├── src                               # source files
├── Tests/
│   └── tests.cpp                 # Integrationstests
│                             
├── build/
│   └── bin/                          # nicht getrackt
└── .github/workflows/ci.yml          # CI/CD Pipeline
```

## Build und Ausführung

### Voraussetzungen
- CMake (≥ 3.10)
- C++11 Compiler (g++ oder clang++)

### Lokaler Build

```bash
# Projektordner
cd CI-CD_Test

# Build-Verzeichnis erstellen
mkdir build
cd build

# CMake konfigurieren
cmake ..

# Bauen
make
```

### Programme ausführen

#### Drehzahlüberwachung testen
```bash
# Aus dem Projektstamm
./build/bin/Drehzahlueberwachung 50    # OK (Exit-Code 0)
./build/bin/Drehzahlueberwachung 75    # ERROR (Exit-Code 1)
```

#### Integrationstests ausführen
```bash
# Aus dem Projektstamm
./Tests/bin/tests

# Ausgabe zeigt 11 Tests mit verschiedenen Werten
# Ergebnisse werden in test_ergebnisse.txt gespeichert
```

## Test-Ergebnisse

Die Tests validieren folgende Szenarien:

| Eingabewert | Erwartet | Exit-Code |
|-------------|----------|-----------|
| 0-5000      | OK       | 0         |
| >5000       | ERROR    | 1         |

**Beispiel-Ausgabe:**
```
=== Integrationstests fuer Drehzahlueberwachung ===
Test 1: Wert 50 (OK erwartet):
  -> PASSED

Test 6: Wert 71 (ERROR erwartet):
  -> PASSED

=== Zusammenfassung ===
Bestandene Tests: 11 von 11
```

## CI/CD

Bei jedem Push oder Pull Request auf den `main` Branch wird automatisch:
1. Der Code gebaut (CMake + make)
2. Die Integrationstests ausgeführt
3. Ergebnisse in GitHub Actions angezeigt

**Manueller Start:** Gehe zu GitHub → Actions → "CI/CD Pipeline" → "Run workflow"

## Verwendung in der Entwicklung

### Lokale Tests
```bash
# Nach Änderungen immer testen
cd build && make
./Tests/bin/tests
```

### Grenzwert anpassen
In `Drehzahlueberwachung.cpp`:
```cpp
const int GRENZWERT = 70;  // Hier ändern
```

### Neue Testwerte hinzufügen
In `Tests/src/tests.cpp` das Array `testWerte[]` erweitern.
