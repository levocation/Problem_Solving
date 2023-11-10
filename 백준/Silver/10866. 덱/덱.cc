#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> dq;

    string op;
    int n, num;

    cin >> n;

    while (n--) {
        cin >> op;
        if (op == "push_front") {
            cin >> num;
            dq.push_front(num);
        } else if (op == "push_back") {
            cin >> num;
            dq.push_back(num);
        }
        else if (op == "pop_front") {
            if (dq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (op == "pop_back") {
            if (dq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (op == "size") {
            cout << dq.size() << '\n';
        }
        else if (op == "empty") {
            cout << (dq.empty() ? 1 : 0) << '\n';
        }
        else if (op == "front") {
            if (dq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << dq.front() << '\n';
            }
        }
        else if (op == "back") {
            if (dq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << dq.back() << '\n';
            }
        }
    }

    return 0;
}