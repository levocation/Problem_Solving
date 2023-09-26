#include <string>
#include <regex>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    vector<int> add_num;
    // 더할 숫자들을 모아놓은 리스트
    // 굳이 리스트를 만든 이유는
    // * 연산자의 경우, 계산하는 숫자 뿐만 아니라
    // 직전에 계산했던 숫자까지 2를 곱하기 때문이다.
    
    int temp_num = 0;
    char bonus = ' ';
    char option = ' ';
    
    for (char ch : dartResult) {
        if (ch - '0' >= 0 && ch - '0' <= 9) {
            // ch는 0~9 사이의 숫자로 된 문자이다.
            
            if (bonus != ' ') {
                // 보너스가 설정된 상태로 숫자를 만났을 경우,
                // 이전 숫자를 계산해 준 뒤에 숫자를 카운팅해야 한다.
                
                if (bonus == 'D') {
                    temp_num = temp_num * temp_num;
                } else if (bonus == 'T') {
                    temp_num = temp_num * temp_num * temp_num;
                }
                
                if (option == '#') {
                    add_num.emplace_back(temp_num * -1);
                } else if (option == '*') {
                    if (add_num.size() >= 1) {
                        add_num[add_num.size() - 1] *= 2;
                    }
                    add_num.emplace_back(temp_num * 2);
                } else {
                    add_num.emplace_back(temp_num);
                }
                
                temp_num = 0;
                bonus = ' ';
                option = ' ';
            }
            
            temp_num = temp_num * 10 + (ch - '0');
        } else if (ch == 'S') {
            // BONUS - S
            bonus = 'S';
        } else if (ch == 'D') {
            // BONUS - D
            bonus = 'D';
        } else if (ch == 'T') {
            // BONUS - T
            bonus = 'T';
        } else if (ch == '*') {
            option = '*';
        } else if (ch == '#') {
            option = '#';
        }
    }
    
    if (bonus != ' ' || option != ' ' || temp_num != ' ') {
        if (bonus == 'D') {
            temp_num = temp_num * temp_num;
        } else if (bonus == 'T') {
            temp_num = temp_num * temp_num * temp_num;
        }

        if (option == '#') {
            add_num.emplace_back(temp_num * -1);
        } else if (option == '*') {
            if (add_num.size() >= 1) {
                add_num[add_num.size() - 1] *= 2;
            }
            add_num.emplace_back(temp_num * 2);
        } else {
            add_num.emplace_back(temp_num);
        }
    }
    
    for (int n : add_num) {
        answer += n;
    }
    
    return answer;
}