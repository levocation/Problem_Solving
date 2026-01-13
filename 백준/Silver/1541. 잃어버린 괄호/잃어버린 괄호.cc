#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0, coefficient = 1, tmp = 0, n = 0;
    string expression;

    cin >> expression;

    expression += '%';

    for (char c : expression) {
        n = c - '0';
        if (n >= 0 && n <= 9) {
            tmp = tmp * 10 + n;
        } else {
            answer += coefficient * tmp;
            tmp = 0;
            if (c == '-') coefficient = -1;
        }
    }

    cout << answer;
    
    return 0;
}