#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    set<int> s;
    int n, tmp;
    cin >> n;
    while (n--) {
        cin >> tmp;
        s.insert(tmp);
    }
    
    for (int i : s) {
        cout << i << ' ';
    }
    return 0;
}