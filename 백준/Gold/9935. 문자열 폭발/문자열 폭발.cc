#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str, bomb;
    vector<char> v;
    bool isBombed = true;
    
    cin >> str >> bomb;
    int bomb_len = bomb.length();
    int str_len = str.length();
    
    for (int i = 0; i < str_len; i++) {
        v.push_back(str[i]);
        if ((v.size()) < bomb_len) continue;
        isBombed = true;
        
        for (int j = 0; j < bomb_len; j++) {
            if (bomb[j] != v[v.size() - bomb_len + j]) {
                isBombed = false;
                break;
            }
        }
        if (!isBombed) continue;
        for (int j = 0; j < bomb_len; j++) v.pop_back();
    }
    
    if ((int)v.size() < 1) {
        cout << "FRULA";
    } else {
        for (char c : v) {
            cout << c;
        }
    }
    
    return 0;
}