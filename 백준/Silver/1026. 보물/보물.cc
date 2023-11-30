#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, sum = 0;
    cin >> n;
    vector<int> a;
    vector<int> b;
    a = vector<int>(n);
    b = vector<int>(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    
    cout << sum;
    
    return 0;
}