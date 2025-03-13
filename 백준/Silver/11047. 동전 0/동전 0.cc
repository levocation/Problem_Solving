#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, k, res = 0;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    while (!v.empty()) {
        int cnt = k / v.back();
        res += cnt;
        k -= cnt * v.back();
        v.pop_back();
    }

    cout << res;
    
    return 0;
}