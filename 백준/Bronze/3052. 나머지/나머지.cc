#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[42] = {0,};
    
    int tmp, answer = 0;
    
    for (int i = 0; i < 10; i++) {
        cin >> tmp;
        arr[tmp % 42]++;
    }
    
    for (int i : arr) {
        if (i) {
            answer++;
        }
    }
    
    cout << answer;
    
    return 0;
}