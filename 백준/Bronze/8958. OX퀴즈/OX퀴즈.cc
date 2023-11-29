#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, cnt = 0, ans = 0;
    cin >> n;
    
    string s;
    
    while (n--) {
        cin >> s;
        cnt = 0;
        ans = 0;
        for (char c : s) {
            if (c == 'O') {
                cnt++;
                ans += cnt;
            } else {
                cnt = 0;
            }
        }
        cout << ans << '\n';
    }
}