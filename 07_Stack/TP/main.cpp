#include <iostream>
#include "stack.h"
using namespace std;

void fillStack_2311104038(stack &S, int nim_last_digit) {
    const char* str;

    switch (nim_last_digit % 4) {
        case 0:
            str = "IFLABJAYA";
            break;
        case 1:
            str = "HALOBANDUNG";
            break;
        case 2:
            str = "PERCAYADIRI";
            break;
        case 3:
            str = "STRUKTURDATA";
            break;
        default:
            str = "";
            break;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        push_2311104038(S, str[i]);
    }
}

void printInfo(stack S) {
    if (isEmpty_2311104038(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        for (int i = 0; i < S.Top; i++) {  
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    stack S;
    createStack_2311104038(S);

    int nim_last_digit;
    cout << "Masukkan digit terakhir NIM: ";
    cin >> nim_last_digit;

    fillStack_2311104038(S, nim_last_digit);

    cout << "Output:" << endl;
    printInfo_2311104038(S);

    cout << "Isi stack sesudah pop:" << endl;
    for (int i = 0; i < 4 && !isEmpty_2311104038(S); i++) {
        pop_2311104038(S);
    }

    printInfo_2311104038(S);

    return 0;
}