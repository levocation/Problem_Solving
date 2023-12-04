#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll arr[101];
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;
    for (int i = 6; i <= 100; i++) {
        arr[i] = arr[i-1] + arr[i-5];
    }
    
    int n;
    cin >> n;
    int t;
    while (n--) {
        cin >> t;
        cout << arr[t] << '\n';
    }
    
    return 0;
}