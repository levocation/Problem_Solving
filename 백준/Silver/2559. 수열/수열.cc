#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, tmp = 0, answer = (1 << 31);
    cin >> n >> m;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        tmp += v[i];
        if (i >= m) {
            tmp -= v[i - m];
        }
        if (i >= m - 1) {
            answer = max(tmp, answer);
        }
    }

    cout << answer;
    
    return 0;
}