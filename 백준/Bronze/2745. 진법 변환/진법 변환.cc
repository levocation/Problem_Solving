#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int format, sum = 0;
    char tmp;
    
    cin >> str >> format;
    int len = str.length();
    
    for (int i = 0; i < len; i++) {
        tmp = str[len - i - 1];
        if ((int)(tmp - '0') < 10) {
            sum += (int)(tmp - '0') * pow(format, i);
        } else {
            sum += (int)(tmp - 55) * pow(format, i);
        }
    }
    
    cout << sum;

    return 0;
}