#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    char buffer = '-';
    int n, count = 0;
    cin >> n;
    
    bool check[26] = {0,};
    
    while (n--) {
        cin >> str;
        for (int i = 0; i < 26; i++) {
            check[i] = 0;
        }
        buffer = '-';
        
        for (char c : str) {
            if (buffer != c) {
                if (!check[(int)(c - 'a')]) {
                    buffer = c;
                    check[(int)(c - 'a')] = true;
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