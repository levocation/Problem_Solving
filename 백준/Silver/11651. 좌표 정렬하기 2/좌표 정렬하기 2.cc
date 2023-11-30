#include <iostream>
#include <utility>
#include <algorithm>

#define X first
#define Y second

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.Y != b.Y) return a.Y < b.Y;
    return a.X < b.X;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    pair<int, int> tmp;
    cin >> n;
    vector<pair<int, int>> v;
    
    while (n--) {
        cin >> tmp.X >> tmp.Y;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end(), comp);
    
    for (pair<int, int> p : v) {
        cout << p.X << ' ' << p.Y << '\n';
    }
    
    return 0;
}