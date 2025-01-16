#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    int arr[10] = {0, };
    
    cin >> num;
    
    while (num != 0) {
        if (num % 10 == 6 || num % 10 == 9) {
            if (arr[6] < arr[9]) arr[6]++;
            else arr[9]++;
        } else {
            arr[num % 10]++;
        }
        num /= 10;
    }
    
    cout << *max_element(arr, arr + 10);
    
    return 0;
}