#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b;
    
    while (true) {
        cin >> a >> b;
        if (!(a | b)) break;
        if (!(a % b)) cout << "multiple\n";
        else if (!(b % a)) cout << "factor\n";
        else cout << "neither\n";
    }
    
    return 0;
}