#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n;
    cin >> n;
    
    set<string, greater<string>> s;
    string name, inout;
    for (long long i = 0; i < n * 2; i++) {
        cin >> name >> inout;
        if (inout == "enter") s.insert(name);
        else s.erase(name);
    }
    
    for (string str : s) {
        cout << str << '\n';
    }
    
    return 0;
}