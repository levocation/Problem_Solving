#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string str;
    
    while (n--) {
        cin >> str;
        cout << str[0] << str[str.length() - 1] << '\n';
    }

    return 0;
}