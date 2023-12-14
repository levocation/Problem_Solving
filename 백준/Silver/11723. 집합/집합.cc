#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    bitset<20> bit(0);
    string str;
    int m, num;
    
    cin >> m;
    while (m--) {
        cin >> str;
        if (str == "add") {
            cin >> num;
            bit.set(num - 1, 1);
        } else if (str == "remove") {
            cin >> num;
            bit.set(num - 1, 0);
        } else if (str == "check") {
            cin >> num;
            cout << bit[num - 1] << '\n';
        } else if (str == "toggle") {
            cin >> num;
            bit.flip(num - 1);
        } else if (str == "all") {
            bit.set();
        } else if (str == "empty") {
            bit.reset();
        }
    }
    
    return 0;
}