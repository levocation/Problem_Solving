#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    vector<char> v;
    for (char c : s) v.push_back(c);
    sort(v.begin(), v.end(), greater<int>());
    for (char c : v) cout << c;
    
    return 0;
}