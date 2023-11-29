#include <iostream>
#include <set>
#include <string>

using namespace std;

bool comp(string a, string b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main() {
    set<string, decltype(&comp)> s(comp);
    int n;
    cin >> n;
    string str;
    while (n--) {
        cin >> str;
        s.insert(str);
    }
    
    for (string asdf : s) {
        cout << asdf << '\n';
    }
}