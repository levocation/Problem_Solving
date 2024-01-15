#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<int> pre(n + 1);
    
    v[1] = 0;
    
    for (int i = 2; i <= n; i++) {
        v[i] = v[i - 1] + 1;
        pre[i] = i - 1;
        
        if (i % 2 == 0 && v[i / 2] + 1 < v[i]) {
            v[i] = v[i / 2] + 1;
            pre[i] = i / 2;
        }
        if (i % 3 == 0 && v[i / 3] + 1 < v[i]) {
            v[i] = v[i / 3] + 1;
            pre[i] = i / 3;
        }
    }
    
    cout << v[n] << '\n';
    int idx = n;
    while (idx != 0) {
        cout << idx << ' ';
        idx = pre[idx];
    }
    
    return 0;
}