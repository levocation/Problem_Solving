#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> A;
vector<vector<int>> R;
vector<vector<int>> M;

int mx = -1;
int sum = 0;

void bring_can_to_cat_maximum_cnt(int depth) {
    if (depth >= k) {
        mx = (sum > mx ? sum : mx);
        return;
    }
    
    bool isBringCan = false;
    
    for (int i = 0; i < n; i++) {
        if (A[i] <= 0) continue;
        A[i]--;
        isBringCan = true;
        for (int j = 0; j < n; j++) {
            if (A[j] <= 0) continue;
            isBringCan = true;
            
            int add_val = R[depth][i] + M[depth][j];
            
            A[j]--;
            sum += add_val;
            
            bring_can_to_cat_maximum_cnt(depth + 1);
            
            A[j]++;
            sum -= add_val;
        }
        A[i]++;
    }
    
    if (!isBringCan) {
        bring_can_to_cat_maximum_cnt(depth + 1);
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> k;
    
    A = vector<int>(n, 0);
    for (int i = 0; i < n; i++) cin >> A[i];
    
    R = vector<vector<int>>(k, vector<int>(n));
    M = vector<vector<int>>(k, vector<int>(n));
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> R[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }
    
    bring_can_to_cat_maximum_cnt(0);
    
    cout << mx;
    
    return 0;
}