#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[26];
    for (int& i : arr) {
        i = -1;
    }
    
    string str;
    cin >> str;
    
    for (int i = 0; i < str.length(); i++) {
        if (arr[(int)(str[i] - 'a')] == -1) {
            arr[(int)(str[i] - 'a')] = i;
        }
    }
    
    for (int i : arr) {
        cout << i << ' ';
    }

    return 0;
}