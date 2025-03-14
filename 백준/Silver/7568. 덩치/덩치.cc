#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> height(n);
    vector<int> weight(n);
    vector<int> rank(n, 1);

    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> height[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (weight[i] > weight[j] && height[i] > height[j]) rank[j]++;
        }
    }

    for (int r : rank) {
        cout << r << ' ';
    }
    
    return 0;
}