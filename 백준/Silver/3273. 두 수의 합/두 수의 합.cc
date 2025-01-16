#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x, res = 0;
    cin >> n;
    
    vector<int> arr(n, 0);
    vector<bool> v(1000001, false);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cin >> x;
    
    for (int num : arr) {
        if (x - num < 0) continue;
        if (v[x - num]) res++;
        v[num] = true;
    }
    
    cout << res;
    
    return 0;
}