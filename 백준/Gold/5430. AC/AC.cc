#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> dq;
    bool isReversed = false, isError = false;

    int t;
    cin >> t;

    int len, number;
    string op;
    string arr;

    while (t--) {
        if (!dq.empty()) dq.clear();
        isReversed = false;
        number = -1;
        isError = false;

        cin >> op;
        cin >> len;
        cin >> arr;

        for (char c : arr) {
            if (c == '[') continue;
            if (c == ',' || c == ']') {
                if (number != -1) {
                    dq.push_back(number);
                    number = -1;
                }
            }
            else {
                number = (int)(c - '0') + (number == -1 ? 0 : number * 10);
            }
        }

        for (char c : op) {
            if (c == 'R') {
                isReversed = !isReversed;
            }
            else if (c == 'D') {
                if (dq.empty()) {
                    isError = true;
                    break;
                }
                else {
                    if (isReversed) {
                        dq.pop_back();
                    }
                    else {
                        dq.pop_front();
                    }
                }
            }
        }

        if (isError) {
            cout << "error\n";
        }
        else {
            cout << '[';
            if (isReversed) {
                auto it = dq.end();
                for (int i = 0; i < (int)(dq.size()); i++) {
                    it--;
                    cout << (i == 0 ? "" : ",") << *it;
                }
            }
            else {
                auto it = dq.begin();
                for (int i = 0; i < (int)(dq.size()); i++) {
                    cout << (i == 0 ? "" : ",") << *it;
                    it++;
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}