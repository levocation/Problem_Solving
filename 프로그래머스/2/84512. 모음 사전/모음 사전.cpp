#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    
    for (int i = 0; i < word.length(); i++) {
        switch (word[i]) {
            case 'A':
                word[i] = '1';
                break;
            case 'E':
                word[i] = '2';
                break;
            case 'I':
                word[i] = '3';
                break;
            case 'O':
                word[i] = '4';
                break;
            case 'U':
                word[i] = '5';
                break;
        }
    }
    
    int num = 1;
    
    for (answer = 1; to_string(num) != word; answer++) {
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