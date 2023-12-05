#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<int> vst;
vector<int> v;

void func(int depth, int num) {
    if (depth >= m) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (vst[i] == 1) continue;
        if (num > arr[i]) continue;
        
        vst[i] = 1;
        v.push_back(arr[i]);
        
        func(depth + 1, arr[i]);
        
        vst[i] = 0;
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    arr = vector<int>(n);
    vst = vector<int>(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    func(0, -1);
    
    return 0;
}