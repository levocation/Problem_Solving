#include <iostream>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    multiset<int> s;
    
    int n, k, a, b;
    long long sum = 0;
    cin >> n >> k;
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr[i] = {b, a};
        // 가치 : b
        // 무게 : a
    }
    sort(arr, arr + n);
    while (k--) {
        cin >> a;
        s.insert(a);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        if (s.lower_bound(arr[i].second) == s.end()) continue;
        sum += arr[i].first;
        s.erase(s.lower_bound(arr[i].second));
    }
    
    cout << sum;
    
    return 0;
}