#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    int arr[n] = {0,};
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        for (int j = 0; j < (b - a + 1) / 2; j++) {
            swap(arr[a + j], arr[b - j]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}