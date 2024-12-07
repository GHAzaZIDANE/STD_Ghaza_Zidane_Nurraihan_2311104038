#include <iostream>
#include <string>
using namespace std;

struct Proyek {
    string namaProyek;
    int durasi;
    Proyek* nextProyek;
};

struct Pegawai {
    string namaPegawai;
    string idPegawai;
    Proyek* headProyek;
    Pegawai* nextPegawai;
};

Pegawai* buatPegawai(string nama, string id) {
    Pegawai* pegawaiBaru = new Pegawai;
    pegawaiBaru->namaPegawai = nama;
    pegawaiBaru->idPegawai = id;
    pegawaiBaru->headProyek = nullptr;
    pegawaiBaru->nextPegawai = nullptr;
    return pegawaiBaru;
}

Proyek* buatProyek(string nama, int durasi) {
    Proyek* proyekBaru = new Proyek;
    proyekBaru->namaProyek = nama;
    proyekBaru->durasi = durasi;
    proyekBaru->nextProyek = nullptr;
    return proyekBaru;
}

void tambahProyek(Pegawai* pegawai, string namaProyek, int durasi) {
    Proyek* proyekBaru = buatProyek(namaProyek, durasi);
    if (pegawai->headProyek == nullptr) {
        pegawai->headProyek = proyekBaru;
    } else {
        Proyek* temp = pegawai->headProyek;
        while (temp->nextProyek != nullptr) {
            temp = temp->nextProyek;
        }
        temp->nextProyek = proyekBaru;
    }
}

void tampilkanData(Pegawai* headPegawai) {
    Pegawai* tempPegawai = headPegawai;
    while (tempPegawai != nullptr) {
        cout << "Nama Pegawai: " << tempPegawai->namaPegawai << ", ID: " << tempPegawai->idPegawai << endl;
        Proyek* tempProyek = tempPegawai->headProyek;
        while (tempProyek != nullptr) {
            cout << "  - Nama Proyek: " << tempProyek->namaProyek << ", Durasi: " << tempProyek->durasi << " bulan" << endl;
            tempProyek = tempProyek->nextProyek;
        }
        tempPegawai = tempPegawai->nextPegawai;
    }
}

void hapusProyek(Pegawai* pegawai, string namaProyek) {
    Proyek* temp = pegawai->headProyek;
    Proyek* prev = nullptr;

    while (temp != nullptr && temp->namaProyek != namaProyek) {
        prev = temp;
        temp = temp->nextProyek;
    }

    if (temp == nullptr) {
        cout << "Proyek tidak ditemukan." << endl;
        return;
    }

    if (prev == nullptr) { 
        pegawai->headProyek = temp->nextProyek;
    } else {
        prev->nextProyek = temp->nextProyek;
    }

    delete temp;
    cout << "Proyek '" << namaProyek << "' berhasil dihapus." << endl;
}

int main() {
    Pegawai* headPegawai = buatPegawai("Andi", "P001");
    headPegawai->nextPegawai = buatPegawai("Budi", "P002");
    headPegawai->nextPegawai->nextPegawai = buatPegawai("Citra", "P003");

    
    tambahProyek(headPegawai, "Aplikasi Mobile", 12); 
    tambahProyek(headPegawai->nextPegawai, "Sistem Akuntansi", 8); 
    tambahProyek(headPegawai->nextPegawai->nextPegawai, "E-commerce", 10); 

    
    tambahProyek(headPegawai, "Analisis Data", 6); 

    hapusProyek(headPegawai, "Aplikasi Mobile");

    tampilkanData(headPegawai);

    return 0;
}