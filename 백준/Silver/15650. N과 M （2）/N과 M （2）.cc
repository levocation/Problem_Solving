#include <iostream>

using namespace std;

int* arr;
int* isused;
int n, m, idx = 0;

void func(int k) {

    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i < n; i++) {
        if (!isused[i]) {
            arr[k] = i + 1;
            isused[i] = 1;
            idx = i;
            func(k + 1);
            isused[i] = 0;
        }
    }
    if (arr[k] == -1) {
        return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    arr = new int[m];
    isused = new int[n];
    for (int i = 0; i < n; i++) {
        isused[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        arr[i] = -1;
    }

    func(0);

    return 0;
}