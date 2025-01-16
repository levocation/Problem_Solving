#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c, res;
    int arr[10] = {0, };
    
    cin >> a >> b >> c;
    res = a * b * c;
    
    while (res != 0) {
        arr[res % 10]++;
        res /= 10;
    }
    
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << '\n';
    }
    
    return 0;
}