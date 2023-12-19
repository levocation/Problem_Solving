#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, idx = 0, num = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> v;
    vector<char> ans;
    
    while (true) {
        if (idx >= n) {
            for (char c : ans) cout << c << '\n';
            break;
        }
        else if (num > n) {
            cout << "NO";
            break;
        }
        if (v.empty() || v.back() != arr[idx]) {
            v.push_back(++num);
            ans.push_back('+');
        } else {
            ans.push_back('-');
            v.pop_back();
            idx++;
        }
    }
    
    return 0;
}