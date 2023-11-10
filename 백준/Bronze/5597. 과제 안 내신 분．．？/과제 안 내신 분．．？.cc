#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[30] = {0,};
    
    int tmp = 0;
    
    for (int i = 0; i < 28; i++) {
        cin >> tmp;
        arr[tmp - 1]++;
    }
    
    for (int i = 0; i < 30; i++) {
        if (!(arr[i])) {
            cout << i + 1 << '\n';
        }
    }
    
    return 0;
}