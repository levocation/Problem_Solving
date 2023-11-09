#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0;
    string s1, s2;
    
    cin >> s1 >> s2;
    
    int arr1[26] = {0,};
    int arr2[26] = {0,};
    
    for (char c : s1) {
        arr1[(int)(c - 'a')]++;
    }
    for (char c : s2) {
        arr2[(int)(c - 'a')]++;
    }
    
    for (int i = 0; i < 26; i++) {
        answer += abs(arr1[i] - arr2[i]);
    }
    
    cout << answer;

    return 0;
}
