#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> v(246914, 1);
    v[1] = 0;
    
    for (long long i = 2; i * i <= 246913; i++) {
        if (!v[i]) continue;
        for (long long j = i * i; j <= 246913; j += i) {
            v[j] = 0;
        }
    }
    int tmp, ans;
    while (true) {
        cin >> tmp;
        if (tmp == 0) break;
        ans = 0;
        for (int i = tmp + 1; i <= tmp * 2; i++) {
            if (v[i]) ans++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}