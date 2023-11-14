#include <iostream>

using namespace std;

int* arr;
int n, m;

void func(int k) {

    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        arr[k] = i + 1;
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    arr = new int[m];

    func(0);

    return 0;
}