#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    string a, b, str = "";
    char ch;
    cin >> a >> b;
    int siz = b.length();
    bool rev = false;
    deque<char> dq;
    
    for (char c : b) {
        dq.push_back(c);
    }
    
    while (true) {
        if (a.length() == siz) break;
        ch = (rev ? dq.front() : dq.back());
        if (rev) dq.pop_front();
        else dq.pop_back();
        if (ch == 'B') rev = !rev;
        siz--;
    }
    while (!dq.empty()) {
        if (rev) {
            str += dq.back();
            dq.pop_back();
        } else {
            str += dq.front();
            dq.pop_front();
        }
    }
    
    cout << (int)(a == str);
}