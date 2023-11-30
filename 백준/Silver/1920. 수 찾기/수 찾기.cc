#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, tmp;
    set<int> s;
    cin >> n;
    while (n--) {
        cin >> tmp;
        s.insert(tmp);
    }
    cin >> m;
    while (m--) {
        cin >> tmp;
        if (s.find(tmp) != s.end()) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
}