#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, mx = -1, pos; // pos는 사분면 위치
    double x, y;
    unordered_map<double, int> m[4]; // 제1사분면, 제2사분면, 제3사분면, 제4사분면
    int zero[4] = {0,}; // 위, 아래, 오른쪽, 왼쪽
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        // #1. x == 0
        if (x == 0) {
            zero[y < 0]++;
            if (zero[y < 0] > mx) mx = zero[y < 0];
        }
        // #2. y == 0
        else if (y == 0) {
            zero[(x < 0) + 2]++;
            if (zero[(x < 0) + 2] > mx) mx = zero[(x < 0) + 2];
        }
        // #3. 어느 사분면에 속함 (x != 0, y != 0)
        else {
            double tmp = y / x;
            
            if (tmp > 0) { // 1사분면 또는 3사분면
                if (x > 0) pos = 1; // 1사분면
                else pos = 3; // 3사분면
            } else { // 2사분면 또는 4사분면
                if (x < 0) pos = 2; // 2사분면
                else pos = 4; // 4사분면
            }
            
            if (m[pos-1].find(tmp) == m[pos-1].end()) m[pos-1].insert({tmp, 1});
            else m[pos-1].find(tmp)->second++;
            
            if (m[pos-1].find(tmp)->second > mx) mx = m[pos-1].find(tmp)->second;
        }
    }
    
    cout << mx;
    
    return 0;
}