#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    set<int> s;
    int n, sum = 0;
    
    while (true) {
        cin >> n;
        if (n == -1) break;
        sum = 0;
        s.clear();
        
        for (int i = 1; i < n; i++) {
            if (!(n % i)) {
                sum += i;
                s.insert(i);
            }
        }
        cout << n;
        if (sum == n) {
            cout << " = 1";
            for (int i : s) {
                if (i == 1) continue;
                cout << " + " << i;
            }
            cout << '\n';
        } else {
            cout << " is NOT perfect.\n";
        }
    }
    
    return 0;
}