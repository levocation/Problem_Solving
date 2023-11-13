#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, format, tmp;
    string str;

    cin >> n >> format;

    while (n != 0) {
        tmp = n % format;
        n /= format;
        if (tmp < 10) {
            str = to_string(tmp) + str;
        }
        else {
            str = (char)(tmp + 55) + str;
        }
    }

    cout << str;
    
    return 0;
}