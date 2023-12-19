#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int v[n];
    vector<int> v2, vec;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v2.push_back(v[i]);
    }
    sort(v2.begin(), v2.end());
    
    vec.push_back(v2[0]);
    for (int i = 1; i < n; i++) {
        if (v2[i] != v2[i-1]) {
            vec.push_back(v2[i]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << (lower_bound(vec.begin(), vec.end(), v[i]) - vec.begin()) << ' ';
    }
    
    return 0;
}