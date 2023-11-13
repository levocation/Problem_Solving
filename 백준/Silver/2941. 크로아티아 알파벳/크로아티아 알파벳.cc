#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;
    
    int len = str.length();
    int ans = 0;
    
    for (int i = 0; i < len; i++) {
        if (i < 1) {
            ans++;
            continue;
        }
        switch (str[i]) {
            case '=':
                if (str[i - 1] != 'c' 
                   && str[i - 1] != 's'
                   && str[i - 1] != 'z') {
                    ans++;
                } else if (str[i - 1] == 'z') {
                    if (i < 2) break;
                    if (str[i - 2] == 'd') ans--;
                }
                break;
            case '-':
                if (str[i - 1] != 'c'
                   && str[i - 1] != 'd') {
                    ans++;
                }
                break;
            case 'j':
                if (str[i - 1] != 'l'
                   && str[i - 1] != 'n') {
                    ans++;
                }
                break;
            default:
                ans++;
        }
    }
    
    cout << ans;
    
    return 0;
}