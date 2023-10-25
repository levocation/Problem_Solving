#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    
    int comp_num = 0;
    
    for (int i = 0; i < word.length(); i++) {
        switch (word[i]) {
            case 'A':
                comp_num = 10 * comp_num + 1;
                break;
            case 'E':
                comp_num = 10 * comp_num + 2;
                break;
            case 'I':
                comp_num = 10 * comp_num + 3;
                break;
            case 'O':
                comp_num = 10 * comp_num + 4;
                break;
            case 'U':
                comp_num = 10 * comp_num + 5;
                break;
        }
    }
    
    int num = 1;
    
    for (answer = 1; num != comp_num; answer++) {
        if (num < 9999) {
            num = 10 * num + 1;
        } else {
            num++;
            for (int i = 4; num % 10 == 6; i--) {
                if (i != 0) {
                    num /= 10;
                    num++;
                } else {
                    num = -1;
                }
            }
            if (num == -1) break;
        }
    }
    
    return answer;
}