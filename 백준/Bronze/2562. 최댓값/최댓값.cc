#include <iostream>

using namespace std;

int main() {
    int max = -1;
    int idx = -1;
    
    int tmp = 0;
    
    for (int i = 0; i < 9; i++) {
        scanf("%d", &tmp);
        
        if (tmp > max) {
            max = tmp;
            idx = i+1;
        }
    }
    
    printf("%d\n%d", max, idx);
}