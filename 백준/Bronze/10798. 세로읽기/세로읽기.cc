#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char arr[5][16] = { ' ', };

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[j][i] == '\0' || arr[j][i] == ' ') continue;
            cout << arr[j][i];
        }
    }

    return 0;
}