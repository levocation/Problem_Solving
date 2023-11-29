#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << (c % a == 0 ? a : c % a) << (c / a + (c % a != 0) < 10 ? "0" : "") << c / a + (c % a != 0) << '\n';
    }
}