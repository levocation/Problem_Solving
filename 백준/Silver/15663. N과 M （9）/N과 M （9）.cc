#include <bits/stdc++.h>

using namespace std;

int n, m;

int input[10]; // 인풋값
int num[10]; // 중복을 제거한 넘버배열
int arr[10];
int usedCnt[10]; // i번째 숫자를 사용가능한 횟수

int len = 1; // num의 길이인데 편의상 변수로 뺌

void func(int k) {
    if (k == m) {
        for (int i = 0; i < k; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < len; i++) {
        if (usedCnt[i] > 0) {
            arr[k] = num[i];
            usedCnt[i]--;
            func(k+1);
            usedCnt[i]++;
            arr[k] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    sort(input, input + n);
    num[0] = input[0];
    usedCnt[0]++;
    for (int i = 1, idx = 0; i < n; i++) {
        if (input[i] != num[idx]) {
            idx++;
            len++;
            num[idx] = input[i];
        }
        usedCnt[idx]++;
    }

    func(0);
    
    return 0;
}