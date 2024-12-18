#include <iostream>
using namespace std;

const int maksimalQueue = 5;    // Maksimal antrian
int front = 0;                  // Penanda antrian depan
int back = 0;                   // Penanda antrian belakang
string queueTeller[5];          // Array untuk menyimpan data antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    return back == maksimalQueue;
}

bool isEmpty() { // Pengecekan apakah antrian kosong
    return back == 0;
}

void enqueueAntrian(string data) { // Fungsi menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Kondisi ketika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Fungsi mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back - 1; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        queueTeller[back - 1] = ""; // Kosongkan posisi terakhir
        back--;
    }
}

int countQueue() { // Fungsi menghitung banyaknya antrian
    return back;
}

void clearQueue() { // Fungsi mengosongkan semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Fungsi untuk menampilkan isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    
    cout << "Jumlah antrian = " << countQueue() << endl;
    
    dequeueAntrian();
    viewQueue();
    
    cout << "Jumlah antrian = " << countQueue() << endl;
    
    clearQueue();
    viewQueue();
    
    cout << "Jumlah antrian = " << countQueue() << endl;
    
    return 0;
}