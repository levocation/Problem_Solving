#include <string>
#include <vector>

using namespace std;

bool pos1[121] = {false,};
bool pos2[121] = {false,};
bool pos3[121] = {false,};

int num = 0;

void func(int depth, int& n) {
    if (depth == n) {
        num++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (pos1[i] || pos2[i + depth] || pos3[depth - i + n - 1]) {
            continue;
        }
        pos1[i] = true;
        pos2[i + depth] = true;
        pos3[depth - i + n - 1] = true;
        func(depth + 1, n);
        pos1[i] = false;
        pos2[i + depth] = false;
        pos3[depth - i + n - 1] = false;
    }
}

int solution(int n) {
    int answer = 0;
    
    num = 0;
    
    func(0, n);
    
    return num;
    
}