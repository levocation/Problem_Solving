#include <iostream>
#include <cmath>
#include <algorithm>

using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, a = 2147483647, b = 0, sum;
    cin >> n;
    ll arr[n];
    ll st = 0, end = n - 1;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    
    while (st < end) {
        sum = arr[st] + arr[end];
        if (sum == 0) {
            a = arr[st];
            b = arr[end];
            break;
        }
        if (abs(sum) < abs(a + b)) {
            a = arr[st];
            b = arr[end];
        }
        if (sum < 0) st++;
        else end--;
    }
    
    if (a > b) {
        ll tmp = a;
        a = b;
        b = tmp;
    }
    
    cout << a << ' ' << b;
    
    return 0;
}