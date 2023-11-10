#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b, A = "", B = "";
    cin >> a >> b;
    
    for (char c : a) {
        A = c + A;
    }
    for (char c : b) {
        B = c + B;
    }

    cout << (stoi(A) > stoi(B) ? A : B);

    return 0;
}