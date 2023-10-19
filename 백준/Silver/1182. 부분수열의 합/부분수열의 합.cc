#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

int s;
int num_cnt;
vector<int> v;

void func(int depth, int number, int count) {
    if (depth == num_cnt) {
        if (count == 0) return;
        if (number == s) cnt++;
        return;
    }
    func(depth + 1, number, count);
    func(depth + 1, number + v[depth], count + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num_cnt >> s;
    
    int tmp = 0;
    for (int i = 0; i < num_cnt; i++) {
        cin >> tmp;
        v.emplace_back(tmp);
    }
    func(0,0,0);
    cout << cnt;
}