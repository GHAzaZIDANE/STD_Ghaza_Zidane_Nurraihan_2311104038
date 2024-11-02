#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

bool isPalindrome(string str) {
    stack<char> s;
    string cleanedStr = "";

    for (char c : str) {
        if (isalpha(c)) {
            c = tolower(c);
            cleanedStr += c;
            s.push(c);
        }
    }

    
    for (char c : cleanedStr) {
        if (c != s.top()) {
            return false; 
        }
        s.pop();
    }
    return true;  
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    if (isPalindrome(kalimat)) {
        cout << "Kalimat tersebut adalah palindrom" << endl;
    } else {
        cout << "Kalimat tersebut adalah bukan palindrom" << endl;
    }

    return 0;
}