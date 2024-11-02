#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

void reverseWords(string kalimat) {
    stack<char> s;

    cout << "Datastack Array : ";
    for (char c : kalimat) {
        s.push(c);  
    }

    cout << endl << "Data : ";
    while (!s.empty()) {
        cout << s.top();  
        s.pop();          
    }
    cout << endl;
}

int main() {
    string kalimat;
    cout << "Masukkan Kata (minimal 3 kata): ";
    getline(cin, kalimat);

    reverseWords(kalimat);

    return 0;
}