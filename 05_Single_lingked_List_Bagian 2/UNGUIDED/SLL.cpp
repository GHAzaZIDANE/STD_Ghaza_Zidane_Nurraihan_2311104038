#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string NIM;      
    string nama;
    Mahasiswa *next;
};

class LinkedList {
private:
    Mahasiswa *head; 

public:

    LinkedList() {
        head = nullptr;
    }

    void tambahMahasiswa(string nim, string nama) {
        Mahasiswa *newNode = new Mahasiswa();
        newNode->NIM = nim;
        newNode->nama = nama;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Mahasiswa *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Data mahasiswa dengan NIM " << nim << " berhasil ditambahkan." << endl;
    }

    void cariMahasiswa(string nim) {
        Mahasiswa *current = head;
        while (current != nullptr) {
            if (current->NIM == nim) {
                cout << "Mahasiswa ditemukan: " << current->nama << endl;
                return;
            }
            current = current->next;
        }
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Mahasiswa *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList listMahasiswa;
    int pilihan;
    string nim, nama;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Cari Mahasiswa\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan NIM: ";
            cin >> nim;
            cin.ignore(); 
            cout << "Masukkan Nama: ";
            getline(cin, nama);
            listMahasiswa.tambahMahasiswa(nim, nama);
            break;

        case 2:
            cout << "Masukkan NIM yang ingin dicari: ";
            cin >> nim;
            listMahasiswa.cariMahasiswa(nim);
            break;

        case 3:
            cout << "Keluar dari program." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 3);

    return 0;
}
