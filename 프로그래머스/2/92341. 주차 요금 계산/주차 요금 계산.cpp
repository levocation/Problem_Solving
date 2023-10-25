#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    // fees[0] : 기본 시간 (분)
    // fees[1] : 기본 요금
    // fees[2] : 몇 분마다 추가요금을 청구할 것인가
    // fees[3] : 추가로 청구할 요금
    
    map<int, int> out_in_list;
    // map<차량번호, 주차한 시간을 00:00 기준으로 분으로>
    
    map<int, int> money_list;
    // map<차량번호, 주차한 단위시간(분)>
    
    int car_num = 0;
    int minute = 0;
    string buffer;
    string in_out = "";
    stringstream ss;
    
    for (string record : records) {
        ss = stringstream(record);
        
        getline(ss, buffer, ' ');
        minute = (int)(buffer[0] - '0') * 600 
                + (int)(buffer[1] - '0') * 60
                + (int)(buffer[3] - '0') * 10
                + (int)(buffer[4] - '0') * 1;
        
        getline(ss, buffer, ' ');
        car_num = stoi(buffer);
        
        getline(ss, buffer, ' ');
        if (buffer == "IN") {
            out_in_list.insert({car_num, minute});
        } else {
            int min = minute - out_in_list.find(car_num)->second;
            //if (min <= fees[0]) {
            //    total = fees[1];
            //} else {
            //    total = fees[1] + ((min / fees[2]) + (min % fees[2] != 0)) * fees[3];
            //}
            
            if (money_list.find(car_num) == money_list.end()) {
                money_list.insert({car_num, min});
            } else {
                money_list.find(car_num)->second += min;
            }
            
            out_in_list.erase(car_num);
        }
    }
    
    minute = 1439;
    // 24시간 = 1440분
    // 23시간 59분 = 1439분
    
    for (auto iter : out_in_list) {
        car_num = iter.first;
        
        int min = minute - iter.second;
        //if (min <= fees[0]) {
        //    total = fees[1];
        //} else {
        //    total = fees[1] + ((min / fees[2]) + (min % fees[2] != 0)) * fees[3];
        //}

        if (money_list.find(car_num) == money_list.end()) {
            money_list.insert({car_num, min});
        } else {
            money_list.find(car_num)->second += min;
        }
    }
    
    int total = 0;
    
    for (auto iter : money_list) {
        if (iter.second <= fees[0]) {
            total = fees[1];
        } else {
            iter.second -= fees[0];
            total = 
                fees[1] + ((iter.second / fees[2]) 
                + (iter.second % fees[2] != 0)) * fees[3];
        }
        
        answer.emplace_back(total);
    }
    
    return answer;
}