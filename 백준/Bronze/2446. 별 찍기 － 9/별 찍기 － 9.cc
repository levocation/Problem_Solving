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
        for (int j = n; j > 0; j--) {
            cout << (j <= abs(i) ? '*' : ' ');
        }
        cout << '*';
        for (int j = 0; j < n; j++) {
            if (j < abs(i)) {
				cout << '*';
            }
        }
        cout << '\n';
    }

    return 0;
}