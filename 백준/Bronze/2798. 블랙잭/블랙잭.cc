#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int sum = 0, mx = -1;
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                sum = arr[i] + arr[j] + arr[k];
                if (sum > mx && sum <= m) mx = sum;
            }
        }
    }
    
    cout << mx;
    
    return 0;
}