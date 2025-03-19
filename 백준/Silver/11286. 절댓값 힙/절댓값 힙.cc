#include <bits/stdc++.h>

using namespace std;

class cmp {
public:
    bool operator() (int a, int b) {
        if (abs(a) != abs(b)) return abs(a) > abs(b);
        return a > 0 && b < 0;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int, vector<int>, cmp> pq; // 최소 힙

    int n, tmp;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == 0) {
            if (pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(tmp);
        }
    }
    
    return 0;
}