#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int board[100001], vst[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int cnt;
    cin >> cnt;
    vector<int> v;
    
    while (cnt--) {
        int t, idx, ans;
        bool b = false;
        cin >> t;
        ans = 0;
        int cur;
        for (int i = 1; i <= t; i++) {
            cin >> idx;
            board[i] = idx;
        }
        
        fill(vst, vst + t + 1, 0);
        for (int i = 1; i <= t; i++) {
            v.clear();
            if (vst[i] == 0) v.push_back(board[i]);
            
            while (!v.empty()) {
                cur = v.back();
                
                if (cur == i) {
                    vst[cur] = 1;
                    break;
                }
                if (vst[cur] != 0) {
                    v.pop_back();
                    b = false;
                    for (int num : v) {
                        if (num == cur) b = true;
                        if (b == false) vst[num] = -1;
                    }
                    break;
                }
                vst[cur] = 1;
                v.push_back(board[cur]);
            }
        }
        
        for (int i = 1; i <= t; i++) {
            if (vst[i] != 1) ans++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}