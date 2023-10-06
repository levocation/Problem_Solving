#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    vector<int> blank;
    // 빈 공간들의 집합이 몇 개의 구역으로 나뉘는지 확인
    // 구역별 빈 공간의 개수를 나타냄
    
    int key = 0;
    // 5g 기지국의 위치를 임시보관
    
    int blank_count = 0;
    
    int station_max_len = 1 + (w * 2);
    // 기지국이 발사할 수 있는 전파의 최대 길이
    
    for (int station : stations) {
        if (stations[0] == station) {
            // 첫 번째 기지국일 경우,
            // 왼쪽에 기지국이 존재하지 않으므로
            // 왼쪽에서 전파를 보낼 수가 없으므로
            // 왼쪽에서 보내는 전파의 길이는 없다.
            // 따라서 케이스를 분리
            
            if (station - w - 1 > key) {
                // 해당 5g 기지국에서 발사한 전파의 최대 거리의 위치가
                // 맨 왼쪽 벽과의 거리가 있는가

                blank_count = station - key - w - 1;
                answer += (blank_count / station_max_len) 
                    + (blank_count % station_max_len != 0);
                
                //blank.emplace_back(station - key - w - 1);
                // 최대 전파의 위치와 왼쪽 벽(또는 기지국) 사이의 빈 공간의 개수
                // 공식 : 현재 기지국 위치 - 이전 기지국 위치 
                //       - 현재 기지국에서 흐르는 전파길이 - 이전 기지국에서 흐르는 전파길이
                //       -1
                // 이때 현재 기지국에서 흐르는 전파길이 = 이전 기지국에서 흐르는 전파길이
                // 따라서 (- 현재 기지국에서 흐르는 전파길이 - 이전 기지국에서 흐르는 전파길이)
                // = -(현재 기지국에서 흐르는 전파길이 * 2)
            }
        } else {
            if (station - w - 1 > key + w) {
                // 해당 5g 기지국에서 발사한 전파의 최대 거리의 위치가
                // 자기보다 왼쪽에 있는 5g 기지국과의 거리가 있는가
                
                blank_count = station - key - (2 * w) - 1;
                answer += (blank_count / station_max_len) 
                    + (blank_count % station_max_len != 0);
                //blank.emplace_back(station - key - (2 * w) - 1);
                // 최대 전파의 위치와 왼쪽 벽(또는 기지국) 사이의 빈 공간의 개수
                // 공식 : 현재 기지국 위치 - 이전 기지국 위치 
                //       - 현재 기지국에서 흐르는 전파길이 - 이전 기지국에서 흐르는 전파길이
                //       -1
                // 이때 현재 기지국에서 흐르는 전파길이 = 이전 기지국에서 흐르는 전파길이
                // 따라서 (- 현재 기지국에서 흐르는 전파길이 - 이전 기지국에서 흐르는 전파길이)
                // = -(현재 기지국에서 흐르는 전파길이 * 2)

            }
        }
        key = station;
    }
    if (key + w < n) {
        // 위 for문은 기지국을 기점으로 왼쪽만 고려했기 때문에
        // 맨 마지막 기지국은 오른쪽도 고려해야 함!
        
        blank_count = n - key - w;
        answer += (blank_count / station_max_len) 
            + (blank_count % station_max_len != 0);
    }
    
    
    return answer;
}