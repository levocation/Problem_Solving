#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for (int i = 0; i < str.length(); i++) {
        if ((int)str[i] >= 97) { // 소문자
            str[i] = (char)(str[i] - 32);
        } else {
            str[i] = (char)(str[i] + 32);
        }
    }
    cout << str;
    return 0;
}