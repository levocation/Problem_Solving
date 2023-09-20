#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    
    int min = 101, max = -101;
    // 최솟값이 -100이고, 최댓값이 100이므로
    // 처음 숫자가 무조건 min과 max에 들어가게끔 설정
    
    for (int i = 0; i < lines.size(); i++) {
        if (lines[i][0] < min) {
                // 최솟값 구하기
                min = lines[i][0];
            }
            if (lines[i][1] > max) {
                // 최댓값 구하기
                max = lines[i][1];
            }
    }
    
    vector<int> v(max - min + 1, 0);
    
    for (int i = 0; i < lines.size(); i++) {
        for (int j = lines[i][0] + (min * (-1)); 
             j < lines[i][1] - (max - v.size() + 1); j++) {
            v[j]++;
        }
    }
    
    for (int count : v) {
        if (count >= 2) {
            answer++;
        }
    }
    
    return answer;
}