#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, s, hap = 0, mx = 1000001;
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int st = 0, ed = 0;
    hap = arr[0];
    
    while (ed < n) {
        if (hap >= s) {
            if (ed - st + 1 < mx) mx = ed - st + 1;
            hap -= arr[st];
            st++;
            if (st > ed) {
                ed = st;
                hap += arr[ed];
            }
        } else {
            ed++;
            if (ed >= n) break;
            hap += arr[ed];
        }
    }
    
    cout << (mx == 1000001 ? 0 : mx);
    
    return 0;
}