#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, tmp;
    cin >> n;
    vector<int> v;
    vector<int> idx;
    
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        if (i == 1) cout << "0 ";
        else {
            while (true) {
                if (v.empty()) {
                    cout << "0 ";
                    break;
                }
                
                if (tmp < v.back()) {
                    cout << idx.back() << ' ';
                    break;
                }
                
                v.pop_back();
                idx.pop_back();
            }
        }
        v.push_back(tmp);
        idx.push_back(i);
    }
    
    return 0;
}