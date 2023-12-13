#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int i, n, mx_len = -1;
vector<string> arr;
string calculated[35];
int idx_arr[35] = { 0, };

bool ch_comp(int idx1, int idx2) {
    return (int)(arr[idx1][i]) < (int)(arr[idx2][i]);
}
bool str_comp(int idx1, int idx2) {
    if (calculated[idx1].length() == calculated[idx2].length()) return calculated[idx1] > calculated[idx2];
    return calculated[idx1].length() > calculated[idx2].length();
    
}

char i_to_c(int num) {
    if (num < 10) return (char)(num + '0');
    return (char)(num - 10 + 'A');
}

int c_to_i(char c) {
    if (c >= 'A' && c <= 'Z') return (int)(c - 'A' + 10);
    return (int)(c - '0');
}

string calc(char ch) {
    string ans = "";
    int sum = 0, carry = 0;

    for (i = 0; i < mx_len; i++) {
        sum = 0;

        for (int j = 0; j < n; j++) {
            if ((int)(arr[j].size()) < i + 1) continue;
            sum += c_to_i((arr[j][i] == ch ? 'Z' : arr[j][i]));
        }
        ans = i_to_c((sum + carry) % 36) + ans;
        carry = (sum + carry) / 36;
    }

    if (carry != 0) {
        while (carry != 0) {
            ans = i_to_c(carry % 36) + ans;
            carry /= 36;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        int len = tmp.length();
        if (len > mx_len) mx_len = len;
        reverse(tmp.begin(), tmp.end());
        arr.push_back(tmp);
    }

    int k;
    cin >> k;

    int change[35] = { 0, }; // 0, 1, 2, 3, ... , X, Y, Z
    vector<int> v;

    for (int i = 0; i < 35; i++) {
        idx_arr[i] = i;
        calculated[i] = calc(i_to_c(i));
    }
    sort(idx_arr, idx_arr + 35, str_comp);

    for (int i = 0; i < k; i++) {
        change[idx_arr[i]] = 1;
    }

    // 숫자 변경 작업
    for (i = mx_len - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if ((int)(arr[j].size()) < i + 1) continue;
            if (arr[j][i] == 'Z') continue;
            if (change[c_to_i(arr[j][i])] != 0) arr[j][i] = 'Z';
        }
    }

    // 진짜 계산
    string ans = calc(' ');
    cout << ans;

    return 0;
}