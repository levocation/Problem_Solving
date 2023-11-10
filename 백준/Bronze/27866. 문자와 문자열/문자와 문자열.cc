#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n;
    cin >> n;
    
    cout << s[n-1];

    return 0;
}