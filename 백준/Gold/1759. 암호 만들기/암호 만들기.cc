#include <bits/stdc++.h>

using namespace std;

int max_depth, n;
vector<char> v;
vector<char> vst;
vector<char> res;

bool isAeiou(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}

void bting(int depth, int last, int aeiou, int bcd) {
    if (depth >= max_depth) {
        /*
        cout << "조합성공 : ";
        for (char c : res) {
            cout << c;
        }
        cout << '\n';
        */
        if (aeiou >= 1 && bcd >= 2) { // 모음 1개 이상, 자음 2개 이상
            for (char c : res) {
                cout << c;
            } 
            cout << '\n';
        }    
        return;
    }

    for (int i = last + 1; i < n; i++) {
        if (!vst[i]) {
            vst[i] = 1;
            res.push_back(v[i]);

            bting(depth + 1, i, aeiou + (isAeiou(v[i]) ? 1 : 0), bcd + (!isAeiou(v[i]) ? 1 : 0));

            res.pop_back();
            vst[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> max_depth >> n;
    v = vector<char>(n);
    vst = vector<char>(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    bting(0, -1, 0, 0);
    
    return 0;
}