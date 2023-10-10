#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    vector<string> cache;
    map<string, bool> m;
    
    if (cacheSize <= 0) {
        // 캐시 저장공간이 없을 경우,
        // 모든 데이터가 cache miss이므로 예외처리
        
        answer = cities.size() * 5;
        return answer;
    }
    
    for (string city : cities) {
        string lower_city = city;
        transform(lower_city.begin(), lower_city.end(), lower_city.begin(), ::tolower);
        if (find(cache.begin(), cache.end(), lower_city) == cache.end()) {
            // 캐시에 데이터가 존재하지 않음
            
            if (cache.size() >= cacheSize) {
                m.erase(cache.front());
                cache.erase(cache.begin());
            }
            
            m.insert({city, true});
            cache.emplace_back(lower_city);
            
            answer += 5;
        } else {
            cache.erase(find(cache.begin(), cache.end(), lower_city));
            cache.emplace_back(lower_city);
            
            answer++;
        }
    }
    
    return answer;
}