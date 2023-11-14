#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int max, a, b, c;

    while (true) {
        cin >> a >> b >> c;
        if (a + b + c == 0) break;
        max = -1;
        if (a > max) max = a;
        if (b > max) max = b;
        if (c > max) max = c;

        if (max >= a + b + c - max) cout << "Invalid\n";
        else if (a == b && b == c && c == a) cout << "Equilateral\n";
        else if (a != b && b != c && c != a) cout << "Scalene\n";
        else cout << "Isosceles\n";
    }

    return 0;
}