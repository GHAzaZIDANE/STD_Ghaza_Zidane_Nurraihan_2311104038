#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertFirst_2311104038(int data) {
        Node* newNode = new Node(data);
        if (!head) head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertLast_2311104038(int data) {
        Node* newNode = new Node(data);
        if (!tail) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteFirst_2311104038() {
        if (!head) return;
        Node* temp = head;
        if (head == tail) head = tail = nullptr;
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteLast_2311104038() {
        if (!tail) return;
        Node* temp = tail;
        if (head == tail) head = tail = nullptr;
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void display_2311104038() {
        Node* current = head;
        cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: ";
        if (!current) cout << "List kosong.";
        while (current) {
            cout << current->data << (current->next ? " <-> " : "");
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertFirst_2311104038(10); 
    dll.insertLast_2311104038(15); 
    dll.insertLast_2311104038(20);

    dll.deleteFirst_2311104038();   
    dll.deleteLast_2311104038();    
    dll.display_2311104038();       
    return 0;
}