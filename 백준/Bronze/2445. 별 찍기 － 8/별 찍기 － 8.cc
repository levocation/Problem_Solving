#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;

    cin >> n;
    n--;
    for (int i = -n; i <= n; i++) {
        for (int j = 0; j < n - abs(i) + 1; j++) {
            cout << '*';
        }
        for (int j = 0; j < 2 * (abs(i)); j++) {
            cout << ' ';
        }
        for (int j = 0; j < n - abs(i) + 1; j++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}