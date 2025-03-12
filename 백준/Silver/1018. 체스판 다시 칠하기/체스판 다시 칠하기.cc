#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string white[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
    };
    string black[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
    };

    int hei, wid;
    cin >> hei >> wid;

    vector<string> v(hei);

    for (int i = 0; i < hei; i++) {
        cin >> v[i];
    }

    int min_val = 2147483647;
    
    for (int i = 0; i <= hei - 8; i++) {
        for (int j = 0; j <= wid - 8; j++) {
            int white_cnt = 0, black_cnt = 0;
            for (int y = 0; y < 8; y++) {
                for (int x = 0; x < 8; x++) {
                    if (v[y + i][x + j] != white[y][x]) white_cnt++;
                    if (v[y + i][x + j] != black[y][x]) black_cnt++;
                }
            }

            min_val = min(min(min_val, white_cnt), black_cnt);
        }
    }

    cout << min_val;
    
    return 0;
}