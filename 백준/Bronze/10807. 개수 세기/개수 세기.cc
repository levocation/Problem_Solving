#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, v, input;
    int arr[201] = {0, };
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> input;
        arr[input + 100]++;
    }
    
    cin >> v;
    
    cout << arr[v + 100];
    
    return 0;
}