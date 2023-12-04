#include <iostream>
#include <vector>

using namespace std;

int mn = 2147483647, mx = -2147483648;
vector<int> num;
int sum = 0, n;
int op[4] = {0,};

void func(int depth) {
    if (depth >= n) {
        if (sum > mx) mx = sum;
        if (sum < mn) mn = sum;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (op[i] < 1) continue;
        
        int tmp = sum;
        if (i == 0) { sum += num[depth]; }
        else if (i == 1) { sum -= num[depth]; }
        else if (i == 2) { sum *= num[depth]; }
        else if (i == 3) { sum /= num[depth]; }
        op[i]--;
        
        func(depth + 1);
        
        sum = tmp;
        op[i]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    num = vector<int>(n);
    
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    
    sum = num[0];
    func(1);
    
    cout << mx << '\n' << mn;
    
    return 0;
}