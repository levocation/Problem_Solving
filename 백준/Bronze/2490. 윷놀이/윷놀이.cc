#include <iostream>

using namespace std;

int main() {
    
    int count;
    int temp;
    
    for (int i = 0; i < 3; i++) {
        count = 0;
        for (int j = 0; j < 4; j++) {
            scanf("%d", &temp);
            count += temp;
        }
        
        switch (count) {
            case 0:
                printf("D\n");
                break;
            case 1:
                printf("C\n");
                break;
            case 2:
                printf("B\n");
                break;
            case 3:
                printf("A\n");
                break;
            case 4:
                printf("E\n");
                break;
        }
    }
    
    return 0;
}