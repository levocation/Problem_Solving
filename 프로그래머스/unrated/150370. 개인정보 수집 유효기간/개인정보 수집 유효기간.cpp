#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    map<string, int> terms_mapset;
    
    stringstream term_ss;
    string buffer;
    string term; // 약관
    
    for (int i = 0; i < terms.size(); i++) {
        term_ss = stringstream(terms[i]);
        
        getline(term_ss, buffer, ' ');
        term = buffer;
        
        getline(term_ss, buffer, ' ');
        int temp = stoi(buffer);
        terms_mapset.insert({term, stoi(buffer)});
        }
    
    int year = 0;
    int month = 0;
    int day = 0;
    // privacies에서 받아올 값
    
    int t_year = 0;
    int t_month = 0;
    int t_day = 0;
    // today의 year, month, day 값
    
    stringstream today_ss(today);
    
    getline(today_ss, buffer, '.');
    t_year = stoi(buffer);
    getline(today_ss, buffer, '.');
    t_month = stoi(buffer);
    getline(today_ss, buffer, '.');
    t_day = stoi(buffer);
    
    stringstream pr_ss;
    
    for (int i = 0; i < privacies.size(); i++) {
        pr_ss = stringstream(privacies[i]);
        getline(pr_ss, buffer, '.');
        year = stoi(buffer);
        getline(pr_ss, buffer, '.');
        month = stoi(buffer);
        getline(pr_ss, buffer, ' ');
        day = stoi(buffer);
        getline(pr_ss, buffer, ' ');
        term = buffer;
        
        month += terms_mapset.find(term)->second;
        
        while (month > 12) {
            month -= 12;
            year++;
        }
        
        if (t_year > year 
           || (t_year == year && t_month > month) 
           || (t_year == year && t_month == month && t_day >= day )) {
            answer.emplace_back(i+1);
        } else {
        }
    }
    return answer;
}