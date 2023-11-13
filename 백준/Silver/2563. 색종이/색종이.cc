#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[100][100] = { 0, };

    int n, w, h, ans = 0;

    cin >> n;

    while (n--) {
        cin >> w >> h;
        w--;
        h--;

        for (int i = h; i < h + 10; i++) {
            for (int j = w; j < w + 10; j++) {
                arr[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            ans += arr[i][j];
        }
    }

    cout << ans;

    return 0;
}