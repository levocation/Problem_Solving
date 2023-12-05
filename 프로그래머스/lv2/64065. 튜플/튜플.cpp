#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
    // 숫자 등장 횟수를 기준으로 내림차순 정렬
}

vector<int> solution(string s) {
    vector<int> answer;
    
    bool isStartNumber = false;
    string tmp_str = "";
    int tmp_num = 0;
    
    map<int, int> mapset;
    // <숫자, 등장 횟수>
    
    for (char ch : s) {
        if (ch - '0' >= 0 && ch - '0' <= 9) {
            // ch가 '0' ~ '9' 일 경우
            // = ch가 숫자로 된 문자일 경우
            
            if (!isStartNumber) {
                // 특수문자만 받다가 처음으로 숫자를 받으면
                
                tmp_str = "";
                // 숫자의 시작일 경우 tmp_str 초기화
                
                isStartNumber = true;
            }
            
            tmp_str += ch;
        } else {
            if (isStartNumber) {
                // 숫자의 바로 뒷 특수문자일 경우
                
                tmp_num = stoi(tmp_str);
                // stoi = string to int
                
                if (mapset.find(tmp_num) == mapset.end()) {
                    // mapset에 숫자가 없다면
                    
                    mapset.insert({tmp_num, 1});
                    // 새로 숫자를 추가하고 기본값은 1
                    
                } else {
                    // 이미 숫자가 있다면
                    
                    mapset.find(tmp_num)->second++;
                    // 횟수를 1 증가
                }
                
                isStartNumber = false;
            }
        }
    }
    
    vector<pair<int, int>> mapset_to_vector(mapset.begin(), mapset.end());
    // map은 오름차순 정렬 고정이므로 vector에 데이터를 옮기기
    
    sort(mapset_to_vector.begin(), mapset_to_vector.end(), comp);
    // pair.second(숫자 등장 횟수) 기준으로 내림차순 정렬
    
    for (auto it = mapset_to_vector.begin(); it != mapset_to_vector.end(); it++) {
        answer.emplace_back(it->first);
    }
    
    return answer;
}