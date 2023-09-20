#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    
    // 로직 요약
    // 선분이 존재할 수 있는 1차원 배열을 만들고
    // 모든 선분에 대하여
    // 해당 배열 안에서 선분이 생긴 자리에 1을 더하면
    // 선분이 겹치는 부분은 값이 2 이상일 수밖에 없으니
    // 값이 2 이상인 원소의 개수를 구하면 된다.
    
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
    // 겹치는 선분의 수를 담는 vector
    // 최솟값이 3이고, 최댓값이 8이라면
    // 3~8은 6칸 이므로 (8 - 3) + 1 을 수행
    
    for (int i = 0; i < lines.size(); i++) {
        // 모든 선분을 가져와서
        // 매 선분마다 해당 선분이 존재하는 곳에 1씩 더한다.
        // 이를 반복하면 두 번 이상 겹치는 선분을 알 수 있다.
        
        // ex
        // min = 0, max = 5
        // v = [0 , 0 , 0 , 0 , 0 , 0]
        // [3, 5] --> v = [0 , 0 , 0 , 1 , 1 , 1]
        // [1, 4] --> v = [0 , 1 , 1 , 2 , 2 , 1]
        // [0, 2] --> v = [1 , 2 , 2 , 2 , 2 , 1]
        
        for (int j = lines[i][0] + (min * (-1)); 
             // lines[i][0] == min    이라면 초기값 = 0
             // lines[i][0] == min + 1이라면 초기값 = 1
             // lines[i][0] == min + n이라면 초기값 = n
             // 이어야 하므로 -(min)을 더해줌으로써
             // min의 부호 여부와 상관없이 값을 보정
             
             j < lines[i][1] - (max - v.size() + 1); 
             j++) {
            // lines[i][1]에 (최댓값 - 배열크기 + 1)을 빼서
            // lines[i][1]의 값을 v에 맞게 보정
            
            v[j]++;
            // 선분이 지나가는 칸의 값을 1 증가
        }
    }
    
    for (int count : v) {
        if (count >= 2) {
            // 해당 칸이 두 개 이상의 선분이 겹치는 칸이라면
            
            answer++;
            // 더해준다.
        }
    }
    
    return answer;
}