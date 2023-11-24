#include <iostream>

using namespace std;

using ll = long long;

ll func(ll a, ll b, ll c) {
    if (b == 1) return a % c;
    ll t = func(a, b / 2, c);
    t = t * t % c;
    return (b % 2 == 0 ? t : t * a % c);
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << func(a, b, c);
}