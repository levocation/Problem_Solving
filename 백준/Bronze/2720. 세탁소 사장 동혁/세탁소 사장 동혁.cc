#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, num, a, b, c, d;
    
    cin >> n;
    
    while (n--) {
        cin >> num;
        a = num / 25;
        num %= 25;
        b = num / 10;
        num %= 10;
        c = num / 5;
        num %= 5;
        d = num;
        
        cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    }
    
    return 0;
}