#include <iostream>

using namespace std;

int* arr;
int n, m, idx;

void func(int k) {

    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i < n; i++) {
        arr[k] = i + 1;
        idx = i;
        func(k + 1);
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
    for (int i = 0; i < m; i++) {
        arr[i] = -1;
    }

    func(0);

    return 0;
}