#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    
    int americano_count = 0;
    int cafelatte_count = 0;
    
    for (int i = 0; i < order.size(); i++) {
        if (order[i] == "anything") {
            americano_count++;
        } else if (order[i].find("americano") != string::npos) {
            americano_count++;
        } else if (order[i].find("cafelatte") != string::npos) {
            cafelatte_count++;
        }
    }
    
    answer = americano_count * 4500 + cafelatte_count * 5000;
    
    return answer;
}