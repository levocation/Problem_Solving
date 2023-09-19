#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for (int i = 0; i < str.length(); i++) {
        printf("%c\n", str[i]);
    }
    return 0;
}