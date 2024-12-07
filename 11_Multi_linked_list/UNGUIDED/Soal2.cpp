#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judul;
    string tanggalPengembalian;
    Buku* nextBuku;
};

struct Anggota {
    string nama;
    string id;
    Buku* headBuku;       
    Anggota* nextAnggota; 
};


Anggota* buatAnggota(string nama, string id) {
    Anggota* anggotaBaru = new Anggota;
    anggotaBaru->nama = nama;
    anggotaBaru->id = id;
    anggotaBaru->headBuku = nullptr;
    anggotaBaru->nextAnggota = nullptr;
    return anggotaBaru;
}

Buku* buatBuku(string judul, string tanggalPengembalian) {
    Buku* bukuBaru = new Buku;
    bukuBaru->judul = judul;
    bukuBaru->tanggalPengembalian = tanggalPengembalian;
    bukuBaru->nextBuku = nullptr;
    return bukuBaru;
}

void tambahBuku(Anggota* anggota, string judul, string tanggalPengembalian) {
    Buku* bukuBaru = buatBuku(judul, tanggalPengembalian);
    if (anggota->headBuku == nullptr) {
        anggota->headBuku = bukuBaru;
    } else {
        Buku* temp = anggota->headBuku;
        while (temp->nextBuku != nullptr) {
            temp = temp->nextBuku;
        }
        temp->nextBuku = bukuBaru;
    }
}

void tampilkanData(Anggota* headAnggota) {
    Anggota* tempAnggota = headAnggota;
    while (tempAnggota != nullptr) {
        cout << "Nama Anggota: " << tempAnggota->nama << ", ID: " << tempAnggota->id << endl;
        Buku* tempBuku = tempAnggota->headBuku;
        while (tempBuku != nullptr) {
            cout << "  - Judul Buku: " << tempBuku->judul << ", Tanggal Pengembalian: " << tempBuku->tanggalPengembalian << endl;
            tempBuku = tempBuku->nextBuku;
        }
        tempAnggota = tempAnggota->nextAnggota;
    }
}

void hapusAnggota(Anggota*& headAnggota, string id) {
    Anggota* temp = headAnggota;
    Anggota* prev = nullptr;

    while (temp != nullptr && temp->id != id) {
        prev = temp;
        temp = temp->nextAnggota;
    }

    if (temp == nullptr) {
        cout << "Anggota tidak ditemukan." << endl;
        return;
    }

    Buku* tempBuku = temp->headBuku;
    while (tempBuku != nullptr) {
        Buku* hapus = tempBuku;
        tempBuku = tempBuku->nextBuku;
        delete hapus;
    }

    if (prev == nullptr) { 
        headAnggota = temp->nextAnggota;
    } else {
        prev->nextAnggota = temp->nextAnggota;
    }

    delete temp;
    cout << "Anggota dengan ID " << id << " beserta buku yang dipinjam telah dihapus." << endl;
}

int main() {
    Anggota* headAnggota = buatAnggota("Rani", "A001");
    headAnggota->nextAnggota = buatAnggota("Dito", "A002");
    headAnggota->nextAnggota->nextAnggota = buatAnggota("Vina", "A003");

   
    tambahBuku(headAnggota, "Pemrograman C++", "01/12/2024"); 
    tambahBuku(headAnggota->nextAnggota, "Algoritma Pemrograman", "15/12/2024"); 
    
    tambahBuku(headAnggota, "Struktur Data", "10/12/2024");

    hapusAnggota(headAnggota, "A002");

    tampilkanData(headAnggota);

    return 0;
}