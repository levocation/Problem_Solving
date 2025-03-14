#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    int res = 1, target = 666, tmp;

    while (res < n) {
        target++;

        if (to_string(target).find("666") != string::npos) res++;
    }

    cout << target;
    
    return 0;
}