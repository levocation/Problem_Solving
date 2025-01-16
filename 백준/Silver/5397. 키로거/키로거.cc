#include <bits/stdc++.h>
using namespace std;

list<char> l;

void printPassword(string s) {
    l = list<char>();
    
    auto cur = l.begin();
    
    for (char command : s) {
        if (command == '<') {
            if (cur != l.begin()) cur--;
        } else if (command == '>') {
            if (cur != l.end()) cur++;
        } else if (command == '-') {
            if (cur != l.begin()) {
                cur--;
                cur = l.erase(cur);
            }
        } else {
            l.insert(cur, command);
        }
    }
    
    for (char c : l) {
        cout << c;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    string s;
    
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cin >> s;
        printPassword(s);
    }
    
    return 0;
}