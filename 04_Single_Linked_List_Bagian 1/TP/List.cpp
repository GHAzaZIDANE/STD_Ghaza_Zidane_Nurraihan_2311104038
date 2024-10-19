#include <iostream>
#include "list.h"
using namespace std;

void createList(List &L) {
    first(L) = NULL;
}

address allocate(infotype x){
    address p = new elmlist;
    info(p) = x;
    next(p) = NULL;

    return p;
}
void insertFirst(List &L, address P){
    next(P) = first(L);
    first(L) = P;
}

void printInfo(List L){

    address p = first(L);
    while (p != NULL) {
        cout << info(p) << ", ";
        p = next(p);
    }
    cout << endl;


}
void insertLast(List &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        address temp = first(L);
        while (next(temp) != NULL) {
            temp = next(temp);
        }
        next(temp) = P;
    }
}

// Search info: Function to search for an element in the list
address searchInfo(List L, infotype x) {
    address P = first(L);
    while (P != NULL) {
        if (info(P) == x) {
            return P;
        }
        P = next(P);
    }
    return NULL;  // Return NULL if not found
}

// Delete last: Delete the last node from the list
void deleteLast(List &L, address &P) {
    if (first(L) == NULL) {
        cout << "List is empty" << endl;
    } else if (next(first(L)) == NULL) {
        P = first(L);
        first(L) = NULL;
    } else {
        address temp = first(L);
        while (next(next(temp)) != NULL) {
            temp = next(temp);
        }
        P = next(temp);
        next(temp) = NULL;
    }
}
