#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int card[20] = {0,};
    
    for (int i = 0; i < 20; i++) {
        card[i] = i + 1;
    }
    
    int n = 0, m = 0;
    int t = 0;
    int tmp = 0;
    for (int i = 0; i < 10; i++) {
        cin >> n >> m;
        n--;
        m--;
        t = (m - n + 1) / 2;
        t += ((m - n + 1) % 2);
        for (int j = 0; j < t; j++) {
            tmp = card[n + j];
            card[n + j] = card[m - j];
            card[m - j] = tmp;
        }
    }
    
    for (int i = 0; i < 20; i++) {
        cout << card[i] << " ";
    }
    
    return 0;
}