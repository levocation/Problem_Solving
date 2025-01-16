#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    int m;
    
    list<char> l;
    char command;
    
    cin >> input;
    
    for (char c : input) {
        l.push_back(c);
    }
    auto cur = l.end();
    
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> command;
        
        if (command == 'L' && cur != l.begin()) {
            cur--;
        } else if (command == 'D' && cur != l.end()) {
            cur++;
        } else if (command == 'B' && cur != l.begin()) {
            cur--;
           cur = l.erase(cur);
        } else if (command == 'P') {
            cin >> command;
            l.insert(cur, command);
        }
    }
    
    for (char c : l) {
        cout << c;
    }
    
    return 0;
}