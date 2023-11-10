#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;

    string op;
    int n, num;

    cin >> n;

    while (n--) {
        cin >> op;
        if (op == "push") {
            cin >> num;
            q.push(num);
        }
        else if (op == "pop") {
            if (q.empty()) {
                cout << "-1\n";
            }
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (op == "size") {
            cout << q.size() << '\n';
        }
        else if (op == "empty") {
            cout << (q.empty() ? 1 : 0) << '\n';
        }
        else if (op == "front") {
            if (q.empty()) {
                cout << "-1\n";
            }
            else {
                cout << q.front() << '\n';
            }
        }
        else if (op == "back") {
            if (q.empty()) {
                cout << "-1\n";
            }
            else {
                cout << q.back() << '\n';
            }
        }
    }

    return 0;
}