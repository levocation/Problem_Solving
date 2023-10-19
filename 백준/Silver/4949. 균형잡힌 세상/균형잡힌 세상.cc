#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;

    vector<char> v;

    while (true) {
        getline(cin, str);
        v.clear();

        if (str == ".") break;

        for (char c : str) {
            if (c == '(' || c == '[') {
                v.emplace_back(c);
            }
            else if (c == ')') {
                if (v.empty()) {
                    v.emplace_back(c);
                    break;
                }
                if (v[v.size() - 1] == '(') {
                    v.pop_back();
                }
                else break;
            }
            else if (c == ']') {
                if (v.empty()) {
                    v.emplace_back(c);
                    break;
                }
                if (v.empty()) break;
                if (v[v.size() - 1] == '[') {
                    v.pop_back();
                }
                else break;
            }
        }
        
        cout << (v.empty() ? "yes\n" : "no\n");
        //t.emplace_back(v.empty() ? "yes" : "no");
    }

    //for (string s : t) {
    //    std::cout << s << "\n";
    //}

    return 0;
}