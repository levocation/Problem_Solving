#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    int A[45], B[45];

    cin >> k;
    A[0] = 0;
    B[0] = 1;
    A[1] = 1;
    B[1] = 1;

    for (int i = 2; i < k; i++) {
        A[i] = A[i - 1] + A[i - 2];
        B[i] = B[i - 1] + B[i - 2];
    }

    cout << A[k - 1] << ' ' << B[k - 1];

    return 0;
}