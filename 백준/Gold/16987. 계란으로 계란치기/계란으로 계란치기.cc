#include <iostream>

using namespace std;

int s[8];
int w[8];
int n, mx = 0;

void func(int idx, int cnt) {
   // if (mx == n) return;
    if (idx >= n) {
        if (cnt > mx) mx = cnt;
        return;
    }
    if (s[idx] < 1) {
        func(idx + 1, cnt);
        return;
    }
    int breaked = 0;
    for (int i = 0; i < n; i++) {
        if (i == idx) continue;
        // i번째 계란이 손에 든 계란(idx번째 계란)과 같은가?
        if (s[i] < 1) continue;
        // 칠 계란의 내구도가 박살났는가?
        int s1 = s[idx], s2 = s[i];
        // s1 : 손에 든 계란의 내구도
        // w1 : 손에 든 계란의 무게
        // s2 : 칠 계란의 내구도
        // w2 : 칠 계란의 무게
        
        s[idx] -= w[i];
        s[i] -= w[idx];
        breaked = 1;
        func(idx + 1, cnt + (s[idx] <= 0) + (s[i] <= 0));
        
        s[idx] = s1;
        s[i] = s2;
    }
    if (breaked == 0) func(idx + 1, cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> w[i];
    }
    
    func(0, 0);
    
    cout << mx;
    
    return 0;
}