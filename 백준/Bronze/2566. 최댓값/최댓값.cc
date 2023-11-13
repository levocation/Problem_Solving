#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0, m = 0, tmp, max = -1;

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> tmp;
            if (tmp > max) {
                max = tmp;
                n = i;
                m = j;
            }
        }
    }

    cout << max << '\n' << n << ' ' << m << '\n';

    return 0;
}