#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a = 0, b = 0;

    cin >> a >> b;

    if (a > b) {
        long long temp = a;
        a = b;
        b = temp;
    }

    if (b - a <= 1) {
        cout << "0\n";
    }
    else {
        cout << b - a - 1 << "\n";
        for (long long i = a + 1; i <= b - 1; i++) {
            cout << i << ' ';
        }
    }

    return 0;
}