#include <string>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    set<pair<pair<int, int>, pair<int, int>>> s;
    // set<pair<pair<이동 전 좌표 x, 이동 전 좌표 y>, pair<이동 후 좌표 x, 이동 후 좌표 y>>>
    
    int x = 0, y = 0;
    
    for (char ch : dirs) {
        switch (ch) {
            case 'U':
                if (y + 1 <= 5) {
                    s.insert(make_pair(make_pair(x, y), make_pair(x, y + 1)));
                    s.insert(make_pair(make_pair(x, y + 1), make_pair(x, y)));
                    y++;
                }
                break;
            case 'D':
                if (y - 1 >= -5) {
                    s.insert(make_pair(make_pair(x, y), make_pair(x, y - 1)));
                    s.insert(make_pair(make_pair(x, y - 1), make_pair(x, y)));
                    y--;
                }
                break;
            case 'L':
                if (x - 1 >= -5) {
                    s.insert(make_pair(make_pair(x, y), make_pair(x - 1, y)));
                    s.insert(make_pair(make_pair(x - 1, y), make_pair(x, y)));
                    x--;
                }
                break;
            case 'R':
                if (x + 1 <= 5) {
                    s.insert(make_pair(make_pair(x, y), make_pair(x + 1, y)));
                    s.insert(make_pair(make_pair(x + 1, y), make_pair(x, y)));
                    x++;
                }
                break;
        }
    }
    
    return (int)(s.size()) / 2;
}