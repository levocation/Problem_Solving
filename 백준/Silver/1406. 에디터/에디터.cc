#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    list<char> l;
    int count = 0;

    cin >> s;
    for (char c : s) {
        l.push_back(c);
    }

    char op;
    char c;

    auto target = l.end();

    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> op;

        if (op == 'L') {
            if (target != l.begin()) target--;
        }
        else if (op == 'D') {
            if (target != l.end()) target++;
        }
        else if (op == 'B') {
            if (target != l.begin()) {
                target--;
                target = l.erase(target);
            }
        }
        else if (op == 'P') {
            cin >> c;
            l.insert(target, c);
        }
    }

    for (auto ch : l) {
        cout << ch;
    }

    return 0;
}
