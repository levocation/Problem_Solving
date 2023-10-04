#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    int min = 0;
    int max = 0;
    
    while (true) {
        if (a - b == 1 || a - b == -1) {
            min = (a < b ? a : b);
            max = a + b - min;
            
            if (max % 2 == 0) {
                break;
            }
        }
        
        a = (a - 1) / 2 + 1;
        b = (b - 1) / 2 + 1;
        
        answer++;
    }

    return answer;
}