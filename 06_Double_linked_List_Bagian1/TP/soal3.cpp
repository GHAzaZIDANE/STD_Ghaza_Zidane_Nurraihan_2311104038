#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertLast_2311104038(int data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward_2311104038() {
        Node* current = head;
        cout << "Daftar elemen dari depan ke belakang: ";
        while (current != nullptr) {
            cout << current->data;
            current = current->next;
            if (current != nullptr) cout << " <-> ";
        }
        cout << endl;
    }

    void displayBackward_2311104038() {
        Node* current = tail;
        cout << "Daftar elemen dari belakang ke depan: ";
        while (current != nullptr) {
            cout << current->data;
            current = current->prev;
            if (current != nullptr) cout << " <-> ";
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertLast_2311104038(1);
    dll.insertLast_2311104038(2);
    dll.insertLast_2311104038(3);
    dll.insertLast_2311104038(4);

    dll.displayForward_2311104038();

    dll.displayBackward_2311104038();

    return 0;
}