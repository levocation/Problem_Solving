#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    string s;

    list<char> l;
    auto cursor = l.end();


    while (n--) {
        cin >> s;

        l.clear();
        cursor = l.end();
        for (char c : s) {
            if (c == '<') {
                if (cursor != l.begin()) cursor--;
            }
            else if (c == '>') {
                if (cursor != l.end()) cursor++;
            }
            else if (c == '-') {
                if (cursor != l.begin()) {
                    cursor--;
                    cursor = l.erase(cursor);
                }
            }
            else {
                l.insert(cursor, c);
            }
        }
        for (char c : l) {
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}
