#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<int> s;
    int len, input;
    
    cin >> len;
    
    for (int i = 0; i < len; i++) {
        cin >> input;
        
        if (input == 0) s.pop();
        else s.push(input);
    }
    
    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    
    cout << sum;
    
    return 0;
}