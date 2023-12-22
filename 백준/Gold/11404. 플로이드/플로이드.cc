#include <iostream>
#include <algorithm>

#define INF 1000000000

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, a, b, w;
    cin >> n >> m;
    
    int arr[n + 1][n + 1] = {0,};
    for (int i = 0; i <= n; i++) fill(arr[i], arr[i] + n + 1, INF);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        arr[a][b] = min(w, arr[a][b]);
    }
    for (int i = 1; i <= n; i++) {
        arr[i][i] = 0;
    }
    
    
    for (int i = 1; i <= n; i++) {
        for (int st = 1; st <= n; st++) {
            for (int en = 1; en <= n; en++) {
                if (arr[st][en] > arr[st][i] + arr[i][en]) {
                    arr[st][en] = arr[st][i] + arr[i][en];
                }
            }
        }
    }
    
    for (int st = 1; st <= n; st++) {
        for (int en = 1; en <= n; en++) {
            cout << (arr[st][en] == INF ? 0 : arr[st][en]) << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}