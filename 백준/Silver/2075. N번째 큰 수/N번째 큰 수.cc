#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙

    long long n, tmp;
    cin >> n;

    for (int i = 0; i < n * n; i++) {
        cin >> tmp;
        pq.push(tmp);

        if (pq.size() > n) pq.pop();
    }

    cout << pq.top();
    
    return 0;
}