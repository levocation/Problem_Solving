#include <bits/stdc++.h>

using namespace std;

// 단조 스택 알고리즘 공부 후 작성
int main()
{
    int len, tmp, key;
    cin >> len;
    
    stack<int> a;
    stack<int> monotonic_stack;
    stack<int> res;
    
    for (int i = 0; i < len; i++) {
        cin >> tmp;
        a.push(tmp);
    }
    
    while (!a.empty()) {
        key = a.top();
        a.pop();
        
        while (true) {
            if (monotonic_stack.empty()) {
                // key보다 오른쪽에 있는 큰 수는 없음
                res.push(-1);
                monotonic_stack.push(key);
                break;
            } else if (monotonic_stack.top() > key) {
                // 이놈이 key의 오큰수
                res.push(monotonic_stack.top());
                monotonic_stack.push(key);
                break;
            } else {
                // key보다 monotonic_stack의 top의 값이 작으므로
                // 큰 값을 찾을 때까지 pop
                monotonic_stack.pop();
            }
        }
    }
    
    while (!res.empty()) {
        cout << res.top() << ' ';
        res.pop();
    }
}