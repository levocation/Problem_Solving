#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, ans;
    cin >> n;
    string tmp;
    
    set<string> s;
    
    while (n--) {
        cin >> tmp;
        if (tmp == "ENTER") {
            s.clear();
        } else {
            if (s.find(tmp) == s.end()) {
                ans++;
                s.insert(tmp);
            }
        }
    }
    
    cout << ans;
    
    return 0;
}