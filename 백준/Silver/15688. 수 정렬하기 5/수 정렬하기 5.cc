#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[2000001] = {0,};
    
    int count = 0;
    
    cin >> count;
    
    int tmp = 0;
    
    for (int i = 0; i < count; i++) {
        cin >> tmp;
        arr[tmp + 1000000]++;
    }
    
    for (int i = 0; i < 2000001; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << i - 1000000 << '\n';
        }
    }
    
    return 0;
}