#include <iostream>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root;

void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node) {
    if (node->left != NULL) return NULL;
    Pohon *baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    return baru;
}

Pohon *insertRight(char data, Pohon *node) {
    if (node->right != NULL) return NULL;
    Pohon *baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    return baru;
}

void showChildren(Pohon *node) {
    if (!node) return;
    if (node->left) cout << "Child Kiri: " << node->left->data << endl;
    if (node->right) cout << "Child Kanan: " << node->right->data << endl;
}

void showDescendants(Pohon *node) {
    if (!node) return;
    if (node->left) {
        cout << "Descendant: " << node->left->data << endl;
        showDescendants(node->left);
    }
    if (node->right) {
        cout << "Descendant: " << node->right->data << endl;
        showDescendants(node->right);
    }
}

int main() {
    init();
    int pilihan;
    char data, parent;
    Pohon *node;

    while (true) {
        cout << "\nMenu:\n1. Buat Node Root\n2. Tambah Child Kiri\n3. Tambah Child Kanan\n4. Tampilkan Child\n5. Tampilkan Descendant\n6. Keluar\nPilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data untuk root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                cout << "Masukkan parent dan child kiri: ";
                cin >> parent >> data;
                node = NULL;
                if (root && root->data == parent) node = root;
                if (node) insertLeft(data, node);
                break;
            case 3:
                cout << "Masukkan parent dan child kanan: ";
                cin >> parent >> data;
                node = NULL;
                if (root && root->data == parent) node = root;
                if (node) insertRight(data, node);
                break;
            case 4:
                cout << "Masukkan node untuk tampilkan child: ";
                cin >> data;
                node = NULL;
                if (root && root->data == data) node = root;
                if (node) showChildren(node);
                break;
            case 5:
                cout << "Masukkan node untuk tampilkan descendant: ";
                cin >> data;
                node = NULL;
                if (root && root->data == data) node = root;
                if (node) showDescendants(node);
                break;
            case 6:
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    }
}
