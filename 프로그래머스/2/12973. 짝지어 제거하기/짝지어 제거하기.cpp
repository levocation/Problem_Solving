#include <iostream>
#include <string>
#include <regex>

using namespace std;

int solution(string s)
{
    vector<char> v;
    for (int i = 0; i < s.length(); ) {
        if (v.size() <= 1) {
            v.emplace_back(s[i]);
            i++;
        } else if (v[v.size() - 1] == v[v.size() - 2]) {
            v.pop_back();
            v.pop_back();
            continue;
        } else {
            v.emplace_back(s[i]);
            i++;
        }
    }
    
    if (v[v.size() - 1] == v[v.size() - 2]) {
        v.pop_back();
        v.pop_back();
    }
    
    return (v.size() < 1);
}