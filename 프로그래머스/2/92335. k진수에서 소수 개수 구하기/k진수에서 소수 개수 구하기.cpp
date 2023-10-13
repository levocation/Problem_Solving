#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    
    string jinsu = "";
    
    while (n != 0) {
        jinsu = to_string(n % k) + jinsu;
        n /= k;
    }
    
    jinsu += "0";
    
    string tmp_str = "";
    long long tmp_int = 0;
    
    bool isSosu = true;
    
    for (int i = 0; i < jinsu.length(); i++) {
        if (jinsu[i] == '0') {
            isSosu = true;
            if (tmp_str == "") continue;
            
            tmp_int = stoll(tmp_str);
            tmp_str = "";
            if (tmp_int <= 1) continue;
            
            for (long long i = 2; i < (long long)(sqrt(tmp_int)) + 1; i++) {
                if (tmp_int % i == 0) {
                    isSosu = false;
                    break;
                }
            }
            
            if (isSosu) {
                answer++;
            }
            
        } else {
            tmp_str += jinsu[i];
        }
    }
    
    return answer;
}