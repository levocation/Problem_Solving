#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 0, m = 0;
    
    cin >> n;
    cin >> m;
    
    int t[n] = {0,};
    
    int a = 0, b = 0, c = 0;
    
    for (int i = 0; i < m; i++) {
        cin >> a;
        cin >> b;
        cin >> c;
        
        for (int j = a - 1; j < b; j++) {
            t[j] = c;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << t[i] << " ";
    }
    
    return 0;
}