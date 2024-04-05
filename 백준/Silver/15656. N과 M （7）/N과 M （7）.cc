#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<int> temp;

void backtracking(int num) {
	if (num >= m) {
		for (int i = 0; i < m; i++) {
			cout << temp[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		temp.push_back(arr[i]);
		backtracking(num + 1);
		temp.pop_back();
	}

}

int main() {
	
	cin >> n >> m;

	arr = vector<int>(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	backtracking(0);

	return 0;
}