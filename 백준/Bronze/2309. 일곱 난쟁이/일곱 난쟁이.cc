#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int temp = 0;
    int num = -100;
    int arr[9] = { 0, };

    for (int i = 0; i < 9; i++) {
        cin >> temp;
        num += temp;
        arr[i] = temp;
    }

    int d[101] = { 0, };

    bool isdeleted = false;

    for (int i = 0; i < 9; i++) {
        if (d[num - arr[i]] == 1 && !isdeleted) {
            d[num - arr[i]] = -1;
            d[arr[i]] = -1;
            isdeleted = true;
        }
        else {
            d[arr[i]] = 1;
        }
    }
    sort(arr, arr + 9);
    for (int i = 0; i < 9; i++) {
        if (d[arr[i]] == 1) {
            cout << arr[i] << '\n';
        }
    }

    return 0;
}