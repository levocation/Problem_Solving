#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    unsigned int bit = 0;
    string str;
    int m, num;
    
    cin >> m;
    while (m--) {
        cin >> str;
        if (str == "add") {
            cin >> num;
            bit |= (1 << num);
        } else if (str == "remove") {
            cin >> num;
            bit &= ~(1 << num);
        } else if (str == "check") {
            cin >> num;
            cout << (bit == (bit | (1 << num))) << '\n';
        } else if (str == "toggle") {
            cin >> num;
            bit ^= (1 << num);
        } else if (str == "all") {
            bit = 0 - 1;
        } else if (str == "empty") {
            bit = 0;
        }
    }
    
    return 0;
}