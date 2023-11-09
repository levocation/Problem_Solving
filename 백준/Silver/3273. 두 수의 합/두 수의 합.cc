#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n[2000001] = {0,};
    
    int tmp = 0, count = 0, answer = 0, target = 0;
    cin >> count;
    int *arr = new int[count];
    
    for (int i = 0; i < count; i++) {
        cin >> tmp;
        arr[i] = tmp;
    }
    cin >> target;
    
    for (int i = 0; i < count; i++) {
        if (target - arr[i] < 0) continue;
        if (n[target - arr[i]]) {
            answer++;
        } else {
            n[arr[i]] = 1;
        }
    }
    
    cout << answer;
    
    return 0;
}