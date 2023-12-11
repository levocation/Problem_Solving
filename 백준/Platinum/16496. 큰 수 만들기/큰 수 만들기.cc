#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
    return a + b > b + a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, cnt = 0;
    cin >> n;
    vector<string> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == "0") cnt++;
    }
    if (v.size() == cnt) {
        cout << 0;
        return 0;
    }
    sort(v.begin(), v.end(), comp);
    
    for (string s : v) cout << s;
    
    return 0;
}