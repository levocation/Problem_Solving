#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[200001] = {0,};
    int n, m;
    cin >> n >> m;
    
    if (n == m) {
        cout << 0;
        return 0;
    }
    
    queue<int> q;
    q.push(n);
    arr[n] = 1;
    
    int cursor;
    
    while (!q.empty()) {
        cursor = q.front();
        q.pop();
        
        if (cursor > 0 && arr[cursor - 1] == 0) {
            arr[cursor - 1] = arr[cursor] + 1;
            if (cursor - 1 == m) {
                cout << arr[cursor - 1] - 1;
                return 0;
            }
            q.push(cursor - 1);
        }
        if (cursor < 100000 && arr[cursor + 1] == 0) {
            arr[cursor + 1] = arr[cursor] + 1;
            if (cursor + 1 == m) {
                cout << arr[cursor + 1] - 1;
                return 0;
            }
            q.push(cursor + 1);
        }
        if (cursor <= 100000 && arr[cursor * 2] == 0) {
            arr[cursor * 2] = arr[cursor] + 1;
            if (cursor * 2 == m) {
                cout << arr[cursor * 2] - 1;
                return 0;
            }
            q.push(cursor * 2);
        }
    }
    
    return 0;
}