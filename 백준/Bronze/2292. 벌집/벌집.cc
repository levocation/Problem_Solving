#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i, j, k;
    cin >> n;

    for (i = 1, j = 1, k = 6; j < n; i++, j += k, k += 6) {}

    cout << i;

    return 0;
}