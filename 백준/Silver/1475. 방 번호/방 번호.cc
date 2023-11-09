#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num = 0;
    cin >> num;
    
    int arr[9] = {0,};
    
    while (num != 0) {
        if (num % 10 == 9) arr[6]++;
        else arr[num % 10]++;
        num /= 10;
    }
    arr[6] = (arr[6] + 1) / 2;
    
    int max = -1;
    
    for (int i : arr) {
        if (i > max) {
            max = i;
        }
    }

    cout << max;
    
    return 0;
}