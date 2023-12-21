#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 에라토스테네스의 체 로 소수 판별
    vector<int> primes;
    vector<bool> is_prime(4000001, true);
    is_prime[1] = false;
    for (ll i = 2; i <= 4000000; i++) {
        if (!is_prime[i]) continue;
        for (ll j = i * i; j <= 4000000; j += i) is_prime[j] = false;
    }
    for (int i = 2; i <= 4000000; i++)
        if (is_prime[i]) primes.push_back(i);
    
    int n, ans = 0, sum = primes[0], len = primes.size();
    cin >> n;
    
    int st = 0, en = 0;
    while (st <= en) {
        if (sum <= n) {
            if (sum == n) ans++;
            en++;
            if (en >= len) break;
            sum += primes[en];
        } else {
            sum -= primes[st];
            st++;
        }
    }
    
    cout << ans;
    
    return 0;
}