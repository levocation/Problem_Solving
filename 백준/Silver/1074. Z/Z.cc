#include <iostream>

using namespace std;

int func(int n, int r, int c) {
    if (n == 0) return 0;
    int half = 1 << (n - 1);
    if (r < half) {
        if (c < half) return func(n - 1, r, c);
        else return half * half + func(n - 1, r, c - half);
    } else {
        if (c < half) return 2 * half * half + func(n - 1, r - half, c);
        else return 3 * half * half + func(n - 1, r - half, c - half);
    }
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c);
}