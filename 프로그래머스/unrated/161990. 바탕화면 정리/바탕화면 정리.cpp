#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int x1 = 51, y1 = 51, x2 = -1, y2 = -1;
    
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[0].size(); j++) {
            if (wallpaper[i][j] == '#') {
                if (x1 > j) x1 = j;
                if (y1 > i) y1 = i;
                if (x2 < j) x2 = j;
                if (y2 < i) y2 = i;
            }
        }
    }
    
    answer.emplace_back(y1);
    answer.emplace_back(x1);
    answer.emplace_back(y2 + 1);
    answer.emplace_back(x2 + 1);
    
    return answer;
}