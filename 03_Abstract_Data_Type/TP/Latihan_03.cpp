#include <iostream>
using namespace std;

int main() {
    int nomer = 10; // Mendeklarasikan variabel integer
    int *ptr;        // Mendeklarasikan pointer ke integer

    ptr = &nomer ;    // Tetapkan alamat 'angka' ke pointer

   // Menampilkan nilai 'angka' menggunakan pointer
    cout << "nilai angka: " << *ptr << endl;  // Pointer dereferensi untuk mendapatkan nilai

    // Menampilkan alamat 'angka' menggunakan pointer
    cout << "alamat nomer : " << ptr << endl;

    return 0;
}
