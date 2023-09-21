#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    vector<int> line;
    
    int len = 0;
    
    for (int i = 0; i < dots.size() - 1; i++) {
        for (int j = i + 1; j < dots.size(); j++) {
            len = sqrt(
                pow((dots[i][1] - dots[j][1]), 2) 
                + pow((dots[i][0] - dots[j][0]), 2)
            );
            line.emplace_back(len);
        }
    }
    
    sort(line.begin(), line.end());
    line.pop_back();
    line.pop_back();
    
    int width = 0, height = 0;
    
    width = line[0];
    height = line[2];
    
    answer = width * height;
    
    return answer;
}