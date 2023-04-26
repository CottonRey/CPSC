#include <fstream>
#include <iostream>

using namespace std;

class LazyCatererSequence {
public:
    LazyCatererSequence() : m_nMax(0), mp_iNumbers(nullptr) {}

    LazyCatererSequence(int n) : m_nMax(n), mp_iNumbers(new int[n]) {}

    ~LazyCatererSequence() {
        delete[] mp_iNumbers;
        cout << "~LazyCatererSequence called" << endl;
    }

    void computeSequence() {
        if (mp_iNumbers == nullptr) {
            cerr << "Sequence array is not allocated." << endl;
            return;
        }

        int pieces = 1;
        mp_iNumbers[0] = 1;
        for (int i = 1; i < m_nMax; i++) {
            pieces += i;
            mp_iNumbers[i] = pieces;
        }
    }

    void saveToFile(const string& filename) {
        if (mp_iNumbers == nullptr) {
            cerr << "Sequence array is not allocated." << endl;
            return;
        }

        ofstream outfile(filename);
        if (outfile.is_open()) {
            for (int i = 0; i < m_nMax; i++) {
                outfile << mp_iNumbers[i] << endl;
            }
            outfile.close();
            cout << "Sequence saved to file " << filename << endl;
        } else {
            cerr << "Unable to open file " << filename << endl;
        }
    }

    void displaySequence() {
        if (mp_iNumbers == nullptr) {
            cerr << "Sequence array is not allocated." << endl;
            return;
        }

        for (int i = 0; i < m_nMax; i++) {
            cout << "n: " << i << ", maximum number of pieces: " << mp_iNumbers[i] << endl;
        }
    }

private:
    int m_nMax;
    int* mp_iNumbers;
};

int main() {
    int n = 11;
    LazyCatererSequence seq(n);
    seq.computeSequence();
    seq.saveToFile("lazy_caterer_sequence.txt");
    seq.displaySequence();
    return 0;
}
