#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, cnt = 0, front_num, back_num;
    cin >> n;
    int answer = n;

    do {
        front_num = (n / 10);
        back_num = (n % 10);
        n = back_num * 10 + ((front_num + back_num) % 10);
        cnt++;
    } while (answer != n);

    cout << cnt;
    
    return 0;
}