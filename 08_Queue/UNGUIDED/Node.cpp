#include <iostream>
#include <string>
using namespace std;

// Mendefinisikan struktur Node untuk linked list
struct Node {
    string nama;
    int NIM;
    Node* next;
};

// Mendefinisikan kelas untuk Priority Queue menggunakan linked list
class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() : front(nullptr) {}

    // Fungsi untuk enqueue berdasarkan prioritas NIM
    void enqueue(string nama, int NIM) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->NIM = NIM;
        newNode->next = nullptr;

        // Jika queue kosong atau NIM baru lebih kecil dari front
        if (front == nullptr || NIM < front->NIM) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* current = front;
            // Menemukan posisi yang tepat berdasarkan NIM
            while (current->next != nullptr && current->next->NIM < NIM) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Fungsi untuk dequeue (menghapus elemen paling depan dari queue)
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue kosong!" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            cout << "Mahasiswa berhasil dihapus dari queue." << endl;
        }
    }

    // Fungsi untuk menampilkan queue
    void display() const {
        if (front == nullptr) {
            cout << "Queue kosong!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue (berdasarkan prioritas NIM): " << endl;
        while (temp != nullptr) {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->NIM << endl;
            temp = temp->next;
        }
    }

    // Destructor untuk membebaskan memori
    ~PriorityQueue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    PriorityQueue pq;
    int pilihan;
    string nama;
    int NIM;

    do {
        cout << "\nMenu:\n1. Tambah Mahasiswa (Enqueue)\n2. Hapus Mahasiswa (Dequeue)\n3. Tampilkan Queue\n4. Keluar\nPilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> NIM;
                pq.enqueue(nama, NIM);
                break;
            case 2:
                pq.dequeue();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Opsi tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);

    return 0;
}
