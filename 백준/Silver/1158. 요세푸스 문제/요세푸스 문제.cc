#include <iostream>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<int> l;
    int n, k;

    cin >> n >> k;

    int mov = 0;

    int *arr = new int[n];

    for (int i = 1; i <= n; i++) {
        l.push_back(i);
    }

    auto focus = l.end();
    focus--;

    for (int i = 0; i < n; i++) {
        mov = k % l.size();

        for (int j = 0; j < mov; j++) {
            if (focus == l.end()) {
                focus = l.begin();
            }
            focus++;
        }
        if (focus == l.end()) {
            focus = l.begin();
        }

        arr[i] = *focus;
        
        focus = l.erase(focus);
        if (focus == l.begin()) {
            focus = l.end();
            if (focus != l.begin()) {
				focus--;
			}
        }
        else {
            focus--;
        }
    }

    cout << '<';

    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i != n - 1 ? ", " : "");
    }

    cout << '>';

    return 0;
}