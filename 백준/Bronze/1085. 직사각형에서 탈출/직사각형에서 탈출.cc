#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x, y, w, h, min = 9999999;
    cin >> x >> y >> w >> h;
    
    int arr[4] = {x, y, w - x, h - y};
    
    for (int n : arr) {
        if (n < min) min = n;
    }
    
    cout << min;
    
    return 0;
}