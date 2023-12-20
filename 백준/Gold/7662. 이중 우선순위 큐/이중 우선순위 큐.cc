#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    multiset<int> s;
    int t, q, num;
    string str;
    cin >> t;
    while (t--) {
        s = multiset<int>();
        cin >> q;
        while (q--) {
            cin >> str >> num;
            if (str == "I") {
                s.insert(num);
            } else {
                if (s.empty()) continue;
                if (num == 1) {
                    s.erase(prev(s.end()));
                } else {
                    s.erase(s.begin());
                }
            }
        }
        if (s.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << *(prev(s.end())) << ' ' << *(s.begin()) << '\n';
        }
    }
    
    return 0;
}