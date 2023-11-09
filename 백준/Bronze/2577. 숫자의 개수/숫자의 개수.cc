#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long sum = 0;
    int a = 0, b = 0, c = 0;
    
    cin >> a >> b >> c;
    sum = a * b * c;
    int arr[10] = {0,};
    
    while (sum != 0) {
        arr[sum % 10]++;
        sum /= 10;
    }
    
    for (int i : arr) {
        cout << i << '\n';
    }
    
    return 0;
}