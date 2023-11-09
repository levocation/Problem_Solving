#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;

    cin >> n;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << ' ';
        }
        for (int j = 0; j < 2 * (i + 1) - 1; j++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}