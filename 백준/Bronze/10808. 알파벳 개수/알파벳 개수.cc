#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    
    cin >> str;
    
    int arr[26] = {0,};
    
    for (char c : str) {
        arr[(int)(c - 'a')]++;
    }
    
    for (int i : arr) {
        cout << i << ' ';
    }

    return 0;
}