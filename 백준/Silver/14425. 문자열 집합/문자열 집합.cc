#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, cnt = 0;
    cin >> n >> m;
    string str;
    set<string> s;
    for (int i = 0; i < n; i++) {
        cin >> str;
        s.insert(str);
    }
    for (int i = 0; i < m; i++) {
        cin >> str;
        if (s.find(str) != s.end()) cnt++;
    }
    
    cout << cnt;
    
    return 0;
}