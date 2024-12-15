#include <iostream>
#include <string>
using namespace std;

int main() {
    int jumlahSimpul;

    cout << "Silakan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    string kota[jumlahSimpul];
    int bobot[jumlahSimpul][jumlahSimpul];

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> kota[i];
    }

    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << kota[i] << " --> " << kota[j] << " = ";
            cin >> bobot[i][j];
        }
    }

    cout << "\nMatriks Bobot Antar Kota:\n";
    cout << "\t";
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << kota[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << kota[i] << "\t";
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << bobot[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
