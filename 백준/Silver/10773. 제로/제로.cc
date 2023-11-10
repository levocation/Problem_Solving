#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    long long sum = 0, k, num;
    
    cin >> k;
    
    while (k--) {
        cin >> num;
        
        if (num) {
            sum += num;
            v.push_back(num);
        } else {
            sum -= v.back();
            v.pop_back();
            
        }
    }
    
    cout << sum;
    
    return 0;
}