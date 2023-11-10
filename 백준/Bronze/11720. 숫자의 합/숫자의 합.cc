#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, sum = 0;
    cin >> n;
    string str;
    cin >> str;
    for (char c : str) {
        sum += ((int)(c - '0'));
    }
    cout << sum;
    return 0;
}