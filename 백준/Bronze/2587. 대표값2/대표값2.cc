#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int sum = 0;
    int temp = 0;
    
    int arr[5] = {0,};
    for (int i = 0; i < 5; i++) {
        scanf("%d", &temp);
        sum += temp;
        arr[i] = temp;
    }
    
    sort(arr, arr + 5);
    
    printf("%d\n%d", sum / 5, arr[2]);
    
    return 0;
}