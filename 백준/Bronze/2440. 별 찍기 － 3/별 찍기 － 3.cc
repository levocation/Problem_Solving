#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}