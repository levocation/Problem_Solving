#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count = 0, n = 0, Y = 0, M = 0;
    cin >> count;

    for (int i = 0; i < count; i++) {
        cin >> n;
        n++;
        Y += (n / 30) * 10 + (n % 30 ? 10 : 0);
        M += (n / 60) * 15 + (n % 60 ? 15 : 0);
    }

    if (Y < M) {
        cout << "Y " << Y;
    }
    else if (Y > M) {
        cout << "M " << M;
    }
    else {
        cout << "Y M " << Y << '\n';
    }

    return 0;
}