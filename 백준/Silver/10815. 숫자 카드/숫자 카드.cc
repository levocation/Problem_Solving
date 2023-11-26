#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    set<int> s;
    
    int n, m, tmp;
    cin >> n;
    
    while (n--) {
        cin >> tmp;
        s.insert(tmp);
    }
    
    cin >> m;
    while (m--) {
        cin >> tmp;
        cout << (s.find(tmp) != s.end()) << ' ';
    }
    
    return 0;
}