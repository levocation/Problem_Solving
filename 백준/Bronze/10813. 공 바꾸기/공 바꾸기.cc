#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    int arr[n];
    for (int i = 1; i <= n; i++) {
        arr[i-1] = i;
    }
    
    int a, b, tmp;
    
    while (m--) {
        cin >> a >> b;
        tmp = arr[a-1];
        arr[a-1] = arr[b-1];
        arr[b-1] = tmp;
    }
    
    for (int i : arr) {
        cout << i << ' ';
    }
    
    return 0;
}