#include <iostream>

using namespace std;

bool isused1[40]; // 열에 대응
bool isused2[40]; // 좌측 하단과 우측 상단 연결. (x, y)에 퀸이 있으면 isused[x+y]
bool isused3[40]; // 좌측 상단과 우측 하단 연결. (x, y)에 퀸이 있으면 isused[x-y + n - 1]

int cnt = 0;
int n = 0;

void func(int cur) {
    if (cur == n) {
        cnt++;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (isused1[i] || isused2[i + cur] || isused3[cur - i + n - 1]) {
            continue;
        }
        isused1[i] = 1;
        isused2[i + cur] = 1;
        isused3[cur - i + n - 1] = 1;
        func(cur + 1);
        isused1[i] = 0;
        isused2[i + cur] = 0;
        isused3[cur - i + n - 1] = 0;
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    func(0);
    cout << cnt;
    return 0;
}