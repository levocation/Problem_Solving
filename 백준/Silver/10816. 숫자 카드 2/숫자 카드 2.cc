#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[20000001] = {0,};
    
    int n, m, tmp;
    cin >> n;
    while (n--) {
        cin >> tmp;
        arr[tmp + 10000000]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        cout << arr[tmp + 10000000] << ' ';
    }
    
    return 0;
}