#include <bits/stdc++.h>

using namespace std;

int n, m, idx;

int num[10];
int arr[10];
int isused[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < k; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i < n; i++) {
        if (!isused[i]) {
            arr[k] = num[i];
            isused[i] = 1;
            idx = i;
            func(k+1);
            isused[i] = 0;
            arr[k] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n);

    func(0);
    
    return 0;
}