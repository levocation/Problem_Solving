#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int sum = 0, mx = -1;
    int n, m;
    cin >> n >> m;
    int arr[n], vis[n] = {0,};
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        sum += arr[i];
        
        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            vis[j] = 1;
            sum += arr[j];
            
            for (int k = 0; k < n; k++) {
                if (vis[k]) continue;
                vis[k] = 1;
                sum += arr[k];
                
                if (sum > mx && sum <= m) mx = sum;
                
                vis[k] = 0;
                sum -= arr[k];
            }
            vis[j] = 0;
            sum -= arr[j];
        }
        vis[i] = 0;
        sum -= arr[i];
    }
    
    cout << mx;
    
    return 0;
}