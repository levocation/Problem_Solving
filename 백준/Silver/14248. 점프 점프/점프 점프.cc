#include <iostream>
#include <vector>
#include <queue>

#define first X
#define second Y

using namespace std;

int main() {

	int cnt, start_pos, pos, result = 0;
	cin >> cnt;

	vector<int> stone_list(cnt);
	vector<int> board(cnt, 0);

	for (int i = 0; i < cnt; i++) {
		cin >> stone_list[i];
	}
	cin >> start_pos;

	vector<int> stack;
	stack.push_back(start_pos - 1); // 1부터 n까지 입력받으므로, 실제 배열상 위치는 0 ~ n-1

	while (!stack.empty()) {
		pos = stack.back();
		stack.pop_back();
		if (board[pos] == 0) {
			result++;
			board[pos] = 1;
		}
		else continue;

		if (pos + stone_list[pos] < cnt 
			&& board[pos + stone_list[pos]] == 0) {
			stack.push_back(pos + stone_list[pos]);
		}
		if (pos - stone_list[pos] >= 0
			&& board[pos - stone_list[pos]] == 0) {
			stack.push_back(pos - stone_list[pos]);
		}
	}

	cout << result;

	return 0;
}