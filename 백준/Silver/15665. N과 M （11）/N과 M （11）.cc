#include <bits/stdc++.h>

using namespace std;

int n, m;

int input[10]; // 인풋값
int num[10]; // 중복을 제거한 넘버배열
int arr[10];

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
        arr[k] = num[i];
        func(k+1);
        arr[k] = 0;
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
    for (int i = 1, idx = 0; i < n; i++) {
        if (input[i] != num[idx]) {
            idx++;
            len++;
            num[idx] = input[i];
        }
    }

    func(0);
    
    return 0;
}