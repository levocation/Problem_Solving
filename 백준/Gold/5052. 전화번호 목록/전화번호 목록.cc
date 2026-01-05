#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<string> s;
    vector<string> v;

    int cnt, c;
    bool isGoodList = false;
    string target;
    cin >> cnt;

    for (int i = 0; i < cnt; i++) {

        cin >> c;
        v = vector<string>(c);
        for (int j = 0; j < c; j++) {
            cin >> v[j];
        }

        sort(v.begin(), v.end()); // string 사전순 정렬

        isGoodList = true;
        target = "--"; // 첫 비교 시에는 아무런 의미없는 문자랑 비교해서 무조건 true 나오도록
        
        for (int j = 0; j < c; j++) {
            if (v[j].find(target) == 0) {
                isGoodList = false;
                break;
            }
            target = v[j];
        }
        if (isGoodList) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}