#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tmp = 0, count = 0, answer = 0, target = 0;
    cin >> count;
    int *arr = new int[count];
    set<int> s;

    for (int i = 0; i < count; i++) {
        cin >> tmp;
        arr[i] = tmp;
        s.emplace(tmp);
    }
    cin >> target;

    for (int i = 0; i < count; i++) {
        if (s.find(target - arr[i]) != s.end()) {
            answer++;
        }
    }

    cout << answer / 2;

    return 0;
}