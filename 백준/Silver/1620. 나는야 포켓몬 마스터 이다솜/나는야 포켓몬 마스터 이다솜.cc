#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    map<int, string> m1;
    map<string, int> m2;
    
    string tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        m1[i] = tmp;
        m2[tmp] = i;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        if (tmp[0] >= '0' && tmp[0] <= '9') { // tmp가 숫자
            cout << m1.find(stoi(tmp))->second << '\n';
        } else {
            cout << m2.find(tmp)->second << '\n';
        }
    }
    
    return 0;
}