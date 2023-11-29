#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr(8);
    vector<int> ass(8);
    vector<int> des(8);
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
        ass[i] = i + 1;
        des[i] = 8 - i;
    }
    
    if (arr == ass) {
        cout << "ascending";
    } else if (arr == des) {
        cout << "descending";
    } else {
        cout << "mixed";
    }
    
    return 0;
}