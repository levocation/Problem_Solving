#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    char buffer = '-';
    int n, count = 0;
    cin >> n;
    
    set<char> s;
    
    while (n--) {
        cin >> str;
        s.clear();
        buffer = '-';
        
        for (char c : str) {
            if (buffer != c) {
                if (s.find(c) == s.end()) {
                    buffer = c;
                    s.insert(c);
                } else {
                    count--;
                    break;
                }
            }
        }
        count++;
    }
    
    cout << count;

    return 0;
}