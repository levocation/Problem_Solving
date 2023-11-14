#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long n, i, j;
    cin >> n;

    for (i = 1, j = 1; j < n; i++, j += i) {}
    n = j - n;

    if (i % 2) {
        cout << (n + 1) << '/' << (i - n);
    }
    else {
        cout << (i - n) << '/' << (n + 1);
    }

    return 0;
}