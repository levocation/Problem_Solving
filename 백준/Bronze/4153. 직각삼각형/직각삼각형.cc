#include <iostream>
#include <algorithm>

using namespace std;

bool func(int arr[]) {
    sort(arr, arr + 3);
    if (arr[0] + arr[1] <= arr[2]) return false;
    if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) return true;
    return false;
}

int main() {
    int arr[3];
    while (true) {
        cin >> arr[0] >> arr[1] >> arr[2];
        if (arr[0] + arr[1] + arr[2] == 0) break;
        if (func(arr)) cout << "right\n";
        else cout << "wrong\n";
    }
}