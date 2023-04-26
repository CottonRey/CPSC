#include <iostream>
using namespace std;

class ECU {
public:
    ECU() : m_bActivatedHydraulicJacks(false), m_bActivatedBeltTires(false), m_bActivatedIRIllumination(false) {}
    ~ECU() {}

    void handleCommand(char command) {
        switch (command) {
            case 'A':
                toggleHydraulicJacks();
                break;
            case 'B':
                toggleBeltTires();
                break;
            case 'E':
                toggleIRIllumination();
                break;
            case 'X':
                cout << "Ignition off." << endl;
                exit(0);
            default:
                cout << "Invalid command." << endl;
        }
    }

private:
    bool m_bActivatedHydraulicJacks;
    bool m_bActivatedBeltTires;
    bool m_bActivatedIRIllumination;

    void toggleHydraulicJacks() {
        m_bActivatedHydraulicJacks = !m_bActivatedHydraulicJacks;
        cout << "Hydraulic Jacks: " << (m_bActivatedHydraulicJacks ? "ON" : "OFF") << endl;
        if (m_bActivatedHydraulicJacks && m_bActivatedBeltTires) {
            toggleBeltTires();
        }
    }

    void toggleBeltTires() {
        m_bActivatedBeltTires = !m_bActivatedBeltTires;
        cout << "Belt Tires: " << (m_bActivatedBeltTires ? "ON" : "OFF") << endl;
    }

    void toggleIRIllumination() {
        m_bActivatedIRIllumination = !m_bActivatedIRIllumination;
        cout << "IR Illumination: " << (m_bActivatedIRIllumination ? "ON" : "OFF") << endl;
    }
};

int main() {
    cout << "Press X to turn off ignition or entering a steering wheel button (A, B, or E)" << endl;
    ECU ecu;
    char command;
    while (true) {
        cout << "    (A)" << endl;
        cout << "(F) (G) (B)" << endl;
        cout << "(E)     (C)" << endl;
        cout << "    (D)" << endl;
        cin >> command;
        ecu.handleCommand(command);
    }
    return 0;
}
