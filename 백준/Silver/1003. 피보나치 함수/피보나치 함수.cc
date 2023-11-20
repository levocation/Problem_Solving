#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int one[41] = { 0, };
    int zero[41] = { 0, };

    one[1] = 1;
    zero[0] = 1;
    zero[1] = 0;
    one[2] = 1;
    zero[2] = 1;

    int tmp, o, z;

    for (int i = 3; i < 41; i++) {
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i - 1] + one[i - 2];
    }

    int n, m;
    cin >> n;

    while (n--) {
        cin >> m;
        cout << zero[m] << ' ' << one[m] << '\n';
    }

    return 0;
}