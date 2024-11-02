#include <iostream>
#include "stack.h"
using namespace std;

void createStack_2311104038(stack &S) {
    S.Top = 0;
}

bool isEmpty_2311104038(stack S) {
    return S.Top == 0;
}

bool isFull_2311104038(stack S) {
    return S.Top == 15;
}

void push_2311104038(stack &S, infotype x) {
    if (!isFull_2311104038(S)) {
        S.Top++;
        S.info[S.Top - 1] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

int pop_2311104038(stack &S) {
    if (!isEmpty_2311104038(S)) {
        infotype x = S.info[S.Top - 1];
        S.Top--;
        return x;
    } else {
        cout << "Stack kosong!" << endl;
        return -1; 
    }
}

void printInfo_2311104038(stack S) {
    if (isEmpty_2311104038(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        for (int i = S.Top - 1; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}