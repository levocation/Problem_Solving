#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool comp(string a, string b) {
    if (a.length() != b.length()) return a.length() < b.length();
    int as = 0, bs = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] >= '0' && a[i] <= '9') as += (int)(a[i] - '0');
        if (b[i] >= '0' && b[i] <= '9') bs += (int)(b[i] - '0');
    }
    if (as != bs) return as < bs;
    
    return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    string arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, comp);
    
    for (int i = 0; i < n; i++) cout << arr[i] << '\n';
    
    return 0;
}