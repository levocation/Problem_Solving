#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> dq;

    string op;
    int n, m, tmp, answer = 0;
    int len = 0;

    cin >> n >> m;

    int arr[m] = {0,};

    for (int i = 0; i < m; i++) {
        cin >> tmp;
        arr[i] = tmp;
    }

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    for (int i = 0; i < m; i++) {
        auto target = find(dq.begin(), dq.end(), arr[i]);
        if (target - dq.begin() > dq.end() - target) {
            answer += (dq.end() - target);
            len = dq.end() - target;
            for (int i = 0; i < len; i++) {
                tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
            }
        }
        else {
            answer += (target - dq.begin());
            len = target - dq.begin();
            for (int i = 0; i < len; i++) {
                tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
            }
        }
        dq.pop_front();
    }

    cout << answer;

    return 0;
}