#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, ans = 0;
    cin >> n;
    vector<char> v;
    string str;
    
    while (n--) {
        v.clear();
        cin >> str;
        
        for (char c : str) {
            if (v.empty()) {
                v.push_back(c);
            } else {
                if (v.back() == c) {
                    v.pop_back();
                } else {
                    v.push_back(c);
                }
            }
        }
        ans += v.empty();
    }
    cout << ans;
    return 0;
}