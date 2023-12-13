#include <set>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, cnt = 0;
    cin >> n >> m;
    
    set<string> s;
    set<string> v;
    string tmp;
    while (n--) {
        cin >> tmp;
        s.insert(tmp);
    }
    while (m--) {
        cin >> tmp;
        if (s.find(tmp) != s.end()) {
            v.insert(tmp);
            cnt++;
        }
    }
    
    cout << cnt << '\n';
    for (string str : v) cout << str << '\n';
    
    return 0;
}