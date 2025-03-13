#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[15][15] = {0, };
    int sum = 0;

    for (int j = 1; j < 15; j++) {
        arr[0][j] = j;
    }

    for (int i = 1; i < 15; i++) {
        for (int j = 1; j < 15; j++) {
            sum = 0;
            for (int g = 1; g <= j; g++) {
                sum += arr[i - 1][g];
            }
            arr[i][j] = sum;
        }
    }

    int t, k, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> k >> n;
        cout << arr[k][n] << '\n';
    }
    
    return 0;
}