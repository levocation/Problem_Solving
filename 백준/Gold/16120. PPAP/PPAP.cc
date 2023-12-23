#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    vector<char> v;
    
    for (char c : s) {
        v.push_back(c);
        if ((int)(v.size()) < 4) continue;
        if (c == 'P' 
                && v[v.size() - 4] == 'P'
                && v[v.size() - 3] == 'P'
                && v[v.size() - 2] == 'A'
                && v[v.size() - 1] == 'P') {
            for (int i = 0; i < 3; i++) v.pop_back();
        }
    }
    
    cout << (v.size() == 1 && v[0] == 'P' ? "PPAP" : "NP");
    
    return 0;
}