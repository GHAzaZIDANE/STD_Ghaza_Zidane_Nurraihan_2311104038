#include <iostream>
using namespace std;

int main() {
    int number = 10; // Mendeklarasikan variabel integer
    int *ptr;        // Mendeklarasikan pointer ke integer

    ptr = &number;    // Tetapkan alamat 'angka' ke pointer

   // Menampilkan nilai 'angka' menggunakan pointer
    cout << "Value of number: " << *ptr << endl;  // Pointer dereferensi untuk mendapatkan nilai

    // Menampilkan alamat 'angka' menggunakan pointer
    cout << "Address of number: " << ptr << endl;

    return 0;
}
