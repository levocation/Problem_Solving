#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int alp[26] = {0,};
    string tmp, ans;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ans = "";
        cin >> tmp;
        fill(alp, alp + 26, 0);
        for (char c : tmp) alp[(int)(c - 'A')]++;
        
        // FIND SI'X'
        for (int j = 0; j < alp[(int)('X' - 'A')];) {
            alp[(int)('S' - 'A')]--;
            alp[(int)('I' - 'A')]--;
            alp[(int)('X' - 'A')]--;
            ans += "6";
        }
        
        // FIND EI'G'HT
        for (int j = 0; j < alp[(int)('G' - 'A')];) {
            alp[(int)('E' - 'A')]--;
            alp[(int)('I' - 'A')]--;
            alp[(int)('G' - 'A')]--;
            alp[(int)('H' - 'A')]--;
            alp[(int)('T' - 'A')]--;
            ans += "8";
        }
        
        // FIND T'W'O
        for (int j = 0; j < alp[(int)('W' - 'A')];) {
            alp[(int)('T' - 'A')]--;
            alp[(int)('W' - 'A')]--;
            alp[(int)('O' - 'A')]--;
            ans += "2";
        }
        
        // FIND FO'U'R
        for (int j = 0; j < alp[(int)('U' - 'A')];) {
            alp[(int)('F' - 'A')]--;
            alp[(int)('O' - 'A')]--;
            alp[(int)('U' - 'A')]--;
            alp[(int)('R' - 'A')]--;
            ans += "4";
        }
        
        // FIND 'Z'ERO
        for (int j = 0; j < alp[(int)('Z' - 'A')];) {
            alp[(int)('Z' - 'A')]--;
            alp[(int)('E' - 'A')]--;
            alp[(int)('R' - 'A')]--;
            alp[(int)('O' - 'A')]--;
            ans += "0";
        }
        
        // FIND TH'R'EE
        for (int j = 0; j < alp[(int)('R' - 'A')];) {
            alp[(int)('T' - 'A')]--;
            alp[(int)('H' - 'A')]--;
            alp[(int)('R' - 'A')]--;
            alp[(int)('E' - 'A')]--;
            alp[(int)('E' - 'A')]--;
            ans += "3";
        }
        
        // FIND 'O'NE
        for (int j = 0; j < alp[(int)('O' - 'A')];) {
            alp[(int)('O' - 'A')]--;
            alp[(int)('N' - 'A')]--;
            alp[(int)('E' - 'A')]--;
            ans += "1";
        }
        
        // FIND 'F'IVE
        for (int j = 0; j < alp[(int)('F' - 'A')];) {
            alp[(int)('F' - 'A')]--;
            alp[(int)('I' - 'A')]--;
            alp[(int)('V' - 'A')]--;
            alp[(int)('E' - 'A')]--;
            ans += "5";
        }
        
        // FIND 'S'EVEN
        for (int j = 0; j < alp[(int)('S' - 'A')];) {
            alp[(int)('S' - 'A')]--;
            alp[(int)('E' - 'A')]--;
            alp[(int)('V' - 'A')]--;
            alp[(int)('E' - 'A')]--;
            alp[(int)('N' - 'A')]--;
            ans += "7";
        }
        
        // FIND 'NINE'
        for (int j = 0; j < alp[(int)('N' - 'A')];) {
            alp[(int)('N' - 'A')]--;
            alp[(int)('I' - 'A')]--;
            alp[(int)('N' - 'A')]--;
            alp[(int)('E' - 'A')]--;
            ans += "9";
        }
        sort(ans.begin(), ans.end());
        cout << "Case #" << i << ": " << ans << '\n';
    }
    
    return 0;
}