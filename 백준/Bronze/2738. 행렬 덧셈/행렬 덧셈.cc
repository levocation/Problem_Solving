#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, tmp;

    cin >> n >> m;

    int** arr = new int*[n];

    for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            arr[i][j] += tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}