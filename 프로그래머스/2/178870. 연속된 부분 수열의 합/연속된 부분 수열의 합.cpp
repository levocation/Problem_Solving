#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int st = 0, en = 0, sum = sequence[0], x = 1000000, y = 10000000;
    
    while (st <= en) {
        if (sum < k) {
            en++;
            if (en >= sequence.size()) break;
            sum += sequence[en];
        } else {
            if (sum == k) {
                if ((en - st == y - x && st < x) || en - st < y - x) {
                    x = st;
                    y = en;
                }
            }
            sum -= sequence[st];
            st++;
        }
    }
    
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}