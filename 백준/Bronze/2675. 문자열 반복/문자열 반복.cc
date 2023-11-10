#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    string str;
    int count;
    
    while (n--) {
        cin >> count >> str;
        for (char c : str) {
            for (int i = 0; i < count; i++) {
                cout << c;
            }
        }
        cout << '\n';
    }

    return 0;
}