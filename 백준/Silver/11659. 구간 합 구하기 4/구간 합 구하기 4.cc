#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    int arr[n + 1];
    arr[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << arr[b] - arr[a-1] << '\n';
    }
    return 0;
}