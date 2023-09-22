#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int p = 0;
    int y = 0;
    
    for (char ch : s) {
        if (ch == 'p' || ch == 'P') p++;
        else if (ch == 'y' || ch == 'Y') y++;
    }

    return p == y;
}