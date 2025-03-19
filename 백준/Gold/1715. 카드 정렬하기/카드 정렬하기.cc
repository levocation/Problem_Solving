#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙

    long long n, tmp, res = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        pq.push(tmp);
    }

    while (!pq.empty()) {
        tmp = pq.top();
        pq.pop();

        if (pq.empty()) cout << res;
        else {
            tmp += pq.top();
            pq.pop();
            res += tmp;
            pq.push(tmp);
        }
    }
    
    return 0;
}