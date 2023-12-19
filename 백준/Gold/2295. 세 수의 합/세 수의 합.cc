#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, ans = -1;
    cin >> n;
    vector<int> v(n), two;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            two.push_back(v[i] + v[j]);
        }
    }
    sort(two.begin(), two.end());
    two.erase(unique(two.begin(), two.end()), two.end());
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (binary_search(two.begin(), two.end(), v[i] - v[j]))
                ans = (v[i] > ans ? v[i] : ans);
        }
    }
    
    cout << ans;
    
    return 0;
}