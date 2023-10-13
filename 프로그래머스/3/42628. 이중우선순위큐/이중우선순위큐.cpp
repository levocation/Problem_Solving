#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2, 0);
    
    string tmp = "";
    
    multimap<int, bool> similarity_queue;
    
    int min = 2147483647;
    int max = -2147483648;
    
    int count = 0;
    
    for (string operation : operations) {
        if (operation[0] == 'I') {
            tmp = "";
            for (int i = 2; i < operation.length(); i++) {
                tmp += operation[i];
            }
            similarity_queue.insert({stoi(tmp), count});
            count++;
            
        } else {
            if (similarity_queue.size() < 1) continue;
            if (operation[2] == '-') {
                // 최솟값 삭제
                similarity_queue.erase(similarity_queue.begin());
            } else {
                // 최댓값 삭제
                auto it = similarity_queue.end();
                it--;
                similarity_queue.erase(it);
            }
        }
    }
    
    if (similarity_queue.size() > 0) {
        auto it = similarity_queue.end();
        it--;
        answer[0] = it->first;
        answer[1] = similarity_queue.begin()->first;
    }
    
    return answer;
}