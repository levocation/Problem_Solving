#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

bool comp(tuple<int, string, int> a, tuple<int, string, int> b) {
    if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
    return get<2>(a) < get<2>(b);
}

int main() {
    vector<tuple<int, string, int>> v;
    int n;
    
    cin >> n;
    int age;
    string name;
    
    while (n--) {
        cin >> age >> name;
        int s = v.size();
        v.push_back(tie(age, name, s));
    }
    
    sort(v.begin(), v.end(), comp);
    
    for (tuple<int, string, int> t : v) {
        cout << get<0>(t) << ' ' << get<1>(t) << '\n';
    }
}