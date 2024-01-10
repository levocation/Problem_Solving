#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q, a, b;
    cin >> n >> q;
    vector<int> v(n + 1);
    vector<int> hap(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) {
        hap[i] = hap[i-1] + v[i];
    }
    
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << hap[b] - hap[a-1] << '\n';
    }
    
    return 0;
}