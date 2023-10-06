#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

map<string, pair<int, vector<int> > > m;
// map<장르, pair<장르별 노래의 합, 노래고유번호_vector> >

vector<int> play_count;

bool comp_genre(string a, string b) {
    return m.find(a)->second.first > m.find(b)->second.first;
}

bool comp_play(int a, int b) {
    if (play_count[a] > play_count[b]) return true;
    else if (play_count[a] < play_count[b]) return false;
    else return a < b;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    play_count = plays;
    
    vector<string> genres_dup_list;
    // 중복이 제거된 genres 리스트
    
    for (int i = 0; i < plays.size(); i++) {
        if (m.find(genres[i]) == m.end()) {
            m.insert({genres[i], make_pair(plays[i], vector<int>(1, i))});
            genres_dup_list.emplace_back(genres[i]);
        } else {
            m.find(genres[i])->second.first += plays[i];
            m.find(genres[i])->second.second.emplace_back(i);
        }
    }
    
    sort(genres_dup_list.begin(), genres_dup_list.end(), comp_genre);
    
    for (string gen : genres_dup_list) {
        vector<int> play_list(m.find(gen)->second.second);
        sort(play_list.begin(), 
            play_list.end(), comp_play);
        
        answer.emplace_back(play_list[0]);
        if (play_list.size() >= 2) {
            answer.emplace_back(play_list[1]);
        }
    }
    return answer;
}