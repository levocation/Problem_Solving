#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> vst(n, 0);
    vector<int> ans;
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < min(n, k); i++) {
        int idx = -1;
        int mx = -1;
        for (int j = 0; j < n; j++) {
            if (vst[j]) continue;
            if (v[j] > mx) {
                mx = v[j];
                idx = j;
            }

        }
        ans.push_back(idx + 1);
        vst[idx] = 1;
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < k; i++) {
        cout << ans[i] << '\n';
    }

    for (int i = 0; i < n; i++) {
        cout << (vst[i] == 0 ? 0 : i + 1) << '\n';
    }

    return 0;
}