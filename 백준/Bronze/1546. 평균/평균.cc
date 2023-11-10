#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    float arr[n] = {0,};
    float sum = 0, max = -1, t;


    for (int i = 0; i < n; i++) {
        cin >> t;
        arr[i] = t;
        if (t > max) max = t;
    }

    for (int i = 0; i < n; i++) {
        sum += (arr[i] / max * 100.0f);
    }

    cout << sum / (float)n;

    return 0;
}