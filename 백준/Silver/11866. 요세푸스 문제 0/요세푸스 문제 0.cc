#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, tmp;
    cin >> a >> b;

    queue<int> q;
    vector<int> v;

    for (int i = 1; i <= a; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        for (int i = 0; i < b - 1; i++) {
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        v.push_back(q.front());
        q.pop();
    }

    cout << "<";
    for (int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << ">";
    
    return 0;
}