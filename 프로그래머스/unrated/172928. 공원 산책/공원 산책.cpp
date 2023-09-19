#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int width = park[0].length();
    int height = park.size();
    
    string buffer;
    string direction;
    int distance;
    
    bool isMeetingObstacle = false;
    
    int x = 0, y = 0;
    
    vector<vector<int>> park_map(height, vector<int>(width, 0));
    
    // vector<string> park에서 장애물 위치 / 시작 위치를 조정
    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[i].length(); j++) {
            if (park[i][j] == 'X') {
                park_map[i][j] = 1;
            } else if (park[i][j] == 'S') {
                x = j;
                y = i;
            }
        }
    }
    
    for (int i = 0; i < routes.size(); i++) {
        stringstream ss(routes[i]);
        
        getline(ss, buffer, ' ');
        direction = buffer;
        getline(ss, buffer, ' ');
        distance = stoi(buffer);
        
        if (direction == "E") {
            if (x + distance > width - 1) {
                continue;
            } else {
                isMeetingObstacle = false;
                for (int i = x; i <= x + distance; i++) {
                    if (park_map[y][i] == 1) {
                        isMeetingObstacle = true;
                    }
                }
                if (isMeetingObstacle) {
                    continue;
                } else {
                    x += distance;
                }
            }
        } else if (direction == "W") {
            if (x - distance < 0) {
                continue;
            } else {
                isMeetingObstacle = false;
                for (int i = x; i >= x - distance; i--) {
                    if (park_map[y][i] == 1) {
                        isMeetingObstacle = true;
                    }
                }
                if (isMeetingObstacle) {
                    continue;
                } else {
                    x -= distance;
                }
            }
        } else if (direction == "S") {
            if (y + distance > height - 1) {
                continue;
            } else {
                isMeetingObstacle = false;
                for (int i = y; i <= y + distance; i++) {
                    if (park_map[i][x] == 1) {
                        isMeetingObstacle = true;
                    }
                }
                if (isMeetingObstacle) {
                    continue;
                } else {
                    y += distance;
                }
            }
        } else if (direction == "N") {
            if (y - distance < 0) {
                continue;
            } else {
                isMeetingObstacle = false;
                for (int i = y; i >= y - distance; i--) {
                    if (park_map[i][x] == 1) {
                        isMeetingObstacle = true;
                    }
                }
                if (isMeetingObstacle) {
                    continue;
                } else {
                    y -= distance;
                }
            }
        }
    }
    
    answer.emplace_back(y);
    answer.emplace_back(x);
    
    return answer;
}