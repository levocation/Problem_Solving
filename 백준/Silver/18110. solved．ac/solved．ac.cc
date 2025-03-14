#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int t = round(n * 0.15);

    double sum = 0;
    
    for (int i = t; i < n - t; i++) {
        sum += v[i];
    }

    if (sum == 0) cout << 0;
    else cout << round(sum / (n - t - t));
    
    return 0;
}