#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[3], max, either;
    cin >> arr[0] >> arr[1] >> arr[2];
    
    max = *max_element(arr, arr + 3);
    either = arr[0] + arr[1] + arr[2] - max;
    
    if (max >= either) {
        max = either - 1;
    }
    
    cout << max + either;
    
    return 0;
}