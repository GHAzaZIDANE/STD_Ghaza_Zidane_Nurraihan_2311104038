#include <iostream>
using namespace std;

// Definisi struct untuk Node
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk menambah node di depan
void insertFront(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head; // Node baru menunjuk ke node pertama (head)
    head = newNode;       // Node baru menjadi head (node pertama)
}

// Fungsi untuk menambah node di belakang
void insertBack(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        // Jika linked list kosong, node baru menjadi head
        head = newNode;
    } else {
        Node* temp = head;
        // Mencari node terakhir
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // Menambahkan node baru di akhir
        temp->next = newNode;
    }
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr; // Awal linked list kosong

    // Tambah node di depan dengan nilai 10
    insertFront(head, 10);

    // Tambah node di belakang dengan nilai 20
    insertBack(head, 20);

    // Tambah node di depan dengan nilai 5
    insertFront(head, 5);

    // Cetak linked list
    cout << "Isi Linked List: ";
    printList(head);

    return 0;
}