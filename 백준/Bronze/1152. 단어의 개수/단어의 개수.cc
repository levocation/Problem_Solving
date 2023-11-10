#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;

    getline(cin, str);
    int ans = 0;

    bool isWord = false;
    for (char c : str) {
        if (c != ' ' && !isWord) {
            isWord = true;
            ans++;
        }
        else if (c == ' ' && isWord) {
			isWord = false;
		}
    }

    cout << ans;

    return 0;
}