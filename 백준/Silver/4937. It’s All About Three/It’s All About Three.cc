#include <iostream>
#include <vector>

#define MAX 1000000

using namespace std;
using ll = long long;

vector<bool> arr(MAX + 1, false);
vector<int> primes;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    for (ll i = 2; i <= MAX; i++) {
        if (arr[i]) continue;
        for (ll j = i * i; j <= MAX; j += i) {
            arr[j] = true;
        }
        arr[i] = true;
        if (i % 10 == 3) primes.push_back(i);
    }
    
    int primes_cnt = primes.size();
    
    int input = 0;
    while (true) {
        cin >> input;
        if (input == -1) break;
        cout << input << ' ';
        if (input == 1) {
            cout << "NO\n";
            continue;
        }
        int cur = 0;
        
        bool is_three = true;
        
        while (cur < primes_cnt && primes[cur] <= input) {
            if (input % primes[cur] == 0) {
                input /= primes[cur];
            } else {
                cur++;
            }
        }
        
        cout << (input == 1 ? "YES\n" : "NO\n");
    }
    
    return 0;
}