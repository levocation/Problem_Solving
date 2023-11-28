#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    
    int arr[n + 1] = {0,};
    arr[1] = 1;
    
    for (int i = 2; i*i <= n; i++) {
        if (arr[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            arr[j] = 1;
        }
    }
    
    for (int i = m; i <= n; i++) {
        if (!arr[i]) cout << i << '\n';
    }
    
    return 0;
}