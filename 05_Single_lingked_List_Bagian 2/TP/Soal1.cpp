#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }

    // Menambahkan elemen baru di akhir list
    void append(int new_data)
    {
        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->next = nullptr;

        if (head == nullptr)
        {
            head = new_node;
            return;
        }

        Node *last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = new_node;
    }

    // Fungsi untuk mencari elemen dalam list
    Node *searchElement(int i, int &position)
    {
        Node *current = head;
        position = 1;

        // Mencari elemen selama current tidak null
        while (current != nullptr)
        {
            if (current->data == i)
            {
                return current;
            }
            current = current->next;
            position++;
        }
        return nullptr;
    }
};

int main()
{
    LinkedList list;
    int element, position;

    // Memasukkan 6 elemen ke dalam list
    cout << "Masukkan 6 elemen integer ke dalam list:\n";
    for (int j = 0; j < 6; j++)
    {
        cout << "Elemen ke-" << j + 1 << ": ";
        cin >> element;
        list.append(element);
    }

    // Meminta pengguna untuk memasukkan elemen yang akan dicari
    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> element;

    // Mencari elemen
    Node *result = list.searchElement(element, position);

    if (result != nullptr)
    {
        cout << "Elemen ditemukan pada alamat: " << result
             << ", posisi: urutan ke-" << position << " dalam list.\n";
    }
    else
    {
        cout << "Elemen " << element << " tidak ditemukan dalam list.\n";
    }

    return 0;
}
