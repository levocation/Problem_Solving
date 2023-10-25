#include <vector>
#include <queue>
#include <utility>

using namespace std;

int answer = 2147483647;

int solution(vector<vector<int>> maps)
{
    answer = 2147483647;
    
    queue<pair<int, pair<int, int>>> bfs;
    
    bfs.push(make_pair(1, make_pair(0, 0)));
    // 플레이어는 항상 (0, 0)에서 시작
    
    int width = maps[0].size();
    int height = maps.size();
    
    pair<int, pair<int, int>> pos;
    // pair<이전 땅의 숫자, pair<x, y>>
    
    int x = 0, y = 0;
    while (true) {
        
        if (bfs.size() <= 0) {
            answer = -1;
            break;
        }
        
        pos = bfs.front();
        
        maps[pos.second.second][pos.second.first] = pos.first;
        
        x = pos.second.first;
        y = pos.second.second;
        
        bfs.pop();
        
        if (x >= width - 1 && y >= height - 1) {
            answer = maps[y][x];
            break;
        }
        
        if (x - 1 >= 0 && maps[y][x - 1] == 1) {
            bfs.push(make_pair(pos.first + 1, make_pair(x - 1, y)));
            maps[y][x - 1] = pos.first + 1;
        }
        if (x + 1 <= width - 1 && maps[y][x + 1] == 1) {
            bfs.push(make_pair(pos.first + 1, make_pair(x + 1, y)));
            maps[y][x + 1] = pos.first + 1;
        }
        if (y - 1 >= 0 && maps[y - 1][x] == 1) {
            bfs.push(make_pair(pos.first + 1, make_pair(x, y - 1)));
            maps[y - 1][x] = pos.first + 1;
        }
        if (y + 1 <= height - 1 && maps[y + 1][x] == 1) {
            bfs.push(make_pair(pos.first + 1, make_pair(x, y + 1)));
            maps[y + 1][x] = pos.first + 1;
        }
    }
    
    return answer;
}