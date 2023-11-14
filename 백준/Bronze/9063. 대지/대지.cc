#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int xmin = 2147483647, xmax = -10001, ymin = 2147483647, ymax = -10001, a, b, n;
    
    cin >> n;
    while (n--) {
        cin >> a >> b;
        if (a < xmin) xmin = a;
        if (a > xmax) xmax = a;
        if (b < ymin) ymin = b;
        if (b > ymax) ymax = b;
    }
    
    cout << (xmax - xmin) * (ymax - ymin);
    
    return 0;
}