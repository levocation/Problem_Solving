#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, v;
    cin >> a >> b >> v;
    cout << (int)ceil((double)(v - b) / (double)(a - b)) << '\n';
    return 0;
}