#include <string>
#include <vector>
#include <utility>
#include <map>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    pair<int, int> left_pos, right_pos;
    left_pos = make_pair(3, 0);
    right_pos = make_pair(3, 2);
    
    map<int, pair<double, double>> m;
    // map<number, pair<y, x>>
    
    m.insert(make_pair(2, make_pair(0, 1)));
    m.insert(make_pair(5, make_pair(1, 1)));
    m.insert(make_pair(8, make_pair(2, 1)));
    m.insert(make_pair(0, make_pair(3, 1)));
    // 2, 5, 8, 0은 0, 1, 2, 3 과 단순한 상관관계를 찾기 힘드므로
    // map에 저장하여 빠르게 (x, y)좌표를 꺼내올 수 있도록 한다.
    
    
    pair<int, int> temp_pair;
    // 거리 비교를 위한 임시 pair
    double distance[2] = {0, 0};
    // 거리 비교 변수 {왼손 거리, 오른손 거리}
    
    for (int num : numbers) {
        if (num == 1 || num == 4 || num == 7) {
            answer += 'L';
            left_pos.first = ((num - 1) / 3);
            left_pos.second = 0;
        } else if (num == 3 || num == 6 || num == 9) {
            answer += 'R';
            right_pos.first = (num / 3 - 1);
            right_pos.second = 2;
        } else {
            temp_pair = m.find(num)->second;
            
            if (left_pos.first == temp_pair.first 
               && left_pos.second == temp_pair.second) {
                answer += 'L';
                continue;
            } else if (right_pos.first == temp_pair.first 
               && right_pos.second == temp_pair.second) {
                answer += 'R';
                continue;
            }
            // 2, 5, 8, 0 중 연속해서 같은 버튼을 누를 경우
            // 아래의 계산을 거치지 않고 바로 버튼을 누른다.
            
            distance[0] = abs(left_pos.first - temp_pair.first) 
                + abs(left_pos.second - temp_pair.second);
            distance[1] = abs(right_pos.first - temp_pair.first) 
                + abs(right_pos.second - temp_pair.second);
            // 기존에 사용하던 두 점 사이의 거리 공식과 달리
            // 상하좌우로만 이동 가능하다는 전제가 있으므로
            // 두 좌표 사이의 x좌표의 차잇값이랑
            // y좌표의 차잇값을 더해서 상하좌우로 이동한 거리를 나타낸다.
            
            if (distance[0] < distance[1]) {
                answer += 'L';
                left_pos.first = temp_pair.first;
                left_pos.second = 1;
            } else if (distance[0] > distance[1]) {
                answer += 'R';
                right_pos.first = temp_pair.first;
                right_pos.second = 1;
            } else {
                if (hand == "left") {
                    answer += 'L';
                    left_pos.first = temp_pair.first;
                    left_pos.second = 1;
                } else if (hand == "right") {
                    answer += 'R';
                    right_pos.first = temp_pair.first;
                    right_pos.second = 1;
                }
            }
        }
    }
    
    return answer;
}