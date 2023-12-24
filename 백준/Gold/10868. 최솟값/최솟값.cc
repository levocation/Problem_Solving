#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define INF 2147483647

using namespace std;

int h, s;
vector<int> arr;
vector<int> num;

int get_min(int idx, int st, int en, int l, int r) {
    if (l > en || r < st) return INF; // l~r이 st~en과 겹치지 않음
    if (l <= st && en <= r) return arr[idx]; // l~r이 st~en에 완전히 포함됨
    
    int mid = (st + en) / 2;
    return min(get_min(idx * 2, st, mid, l, r), get_min(idx * 2 + 1, mid + 1, en, l, r));
}

void init(int idx, int st, int en) {
    if (st == en) arr[idx] = num[st];
    else {
        int mid = (st + en) / 2;
        init(idx * 2, st, mid);
        init(idx * 2 + 1, mid + 1, en);
        arr[idx] = min(arr[idx * 2], arr[idx * 2 + 1]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, a, b;
    cin >> n >> m;
    h = (int)ceil(log2(n));
    s = (1 << (h + 1));
    arr = vector<int>(s, INF);
    num = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> num[i];
    
    init(1, 0, n - 1);
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << get_min(1, 0, n-1, a - 1, b - 1) << '\n';
    }
    
    return 0;
}