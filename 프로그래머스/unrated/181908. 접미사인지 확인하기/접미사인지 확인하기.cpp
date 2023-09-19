#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    
    int answer = 0;
    
    if (my_string.find(is_suffix) == string::npos) {
        answer = 0;
    } else {
        int idx = my_string.find(is_suffix);
        if (my_string.substr(my_string.size() - is_suffix.size(),
                             is_suffix.size())
            == is_suffix) {
            answer = 1;
        }
    }
    
    return answer;
}