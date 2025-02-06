#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);

    tm local_tm = *localtime(&now_time);

    cout << put_time(&local_tm, "%Y-%m-%d");

    return 0;
}