#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int cnt, x, y, result = 0;

	cin >> cnt;

	vector<vector<int>> pos(cnt, vector<int>());

	for (int i = 0; i < cnt; i++) {
		cin >> x >> y;
		pos[y - 1].push_back(x); // 해당 색깔의 vector에 좌표 push
	}
	
	for (vector<int> v : pos) {
		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			if (i == 0) { // 첫 번째 값일 경우
				result += (v[1] - v[0]);
			}
			else if (i == v.size() - 1) { // 마지막 값일 경우
				result += (v[v.size() - 1] - v[v.size() - 2]);
			}
			else {
				int a = v[i] - v[i - 1];
				int b = v[i + 1] - v[i];
				result += (a < b ? a : b);
			}
		}
	}

	cout << result;

	return 0;
}