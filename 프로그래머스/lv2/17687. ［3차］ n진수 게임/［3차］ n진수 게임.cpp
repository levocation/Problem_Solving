#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string str = "";
    string tmp_str = "";
    int tmp_num = 0;
    
    for (int i = 0, num = 0; i < t * m; num++) {
        tmp_str = "";
        tmp_num = num;
        
        do {
            
            switch (tmp_num % n) {
                case 10:
                    tmp_str = "A" + tmp_str;
                    break;
                case 11:
                    tmp_str = "B" + tmp_str;
                    break;
                case 12:
                    tmp_str = "C" + tmp_str;
                    break;
                case 13:
                    tmp_str = "D" + tmp_str;
                    break;
                case 14:
                    tmp_str = "E" + tmp_str;
                    break;
                case 15:
                    tmp_str = "F" + tmp_str;
                    break;
                default:
                    tmp_str = to_string(tmp_num % n) + tmp_str;
                    break;
            }
            tmp_num /= n;
            i++;
            
        } while (tmp_num != 0);
        str += tmp_str;
    }
    
    for (int i = 0; i < t; i++) {
        answer += str[i * m + p - 1];
    }
    
    return answer;
}