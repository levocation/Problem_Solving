#include <iostream>
#include <string>
#include <vector>
#include <utility>

#define X first
#define Y second

using namespace std;
int n, m, sum = 0;
char op = ' ';
string str;

vector<pair<int, int>> ans;
vector<vector<char>> board(3, vector<char>(3, ' '));
int vst[3][3] = { 0, };
bool ok = false;

void func(int x, int y, int sum, int depth) {
    if (ok) return;
    if (depth >= m) {
        if (sum == n) {
            cout << "1\n";
            for (pair<int, int> p : ans) {
                cout << p.X << ' ' << p.Y << '\n';
            }
            ok = true;
        }
        return;
    }
    if (x < 0 || x >= 3 || y < 0 || y >= 3) return;
    if (vst[x][y] != 0) return;

    vst[x][y] = 1;
    ans.push_back({ x, y });
    char tmp_op = op;
    int tmp_sum = sum;

    if (board[x][y] == '+') op = '+';
    else if (board[x][y] == '-') op = '-';
    else {
        if (op == '-') sum -= (int)(board[x][y] - '0');
        else sum += (int)(board[x][y] - '0');
    }

    /*for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << vst[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "depth = " << depth << " , " << "sum is " << sum << "\n";
    cout << "-------------------\n";*/

    func(x + 1, y, sum, depth + 1);
    func(x - 1, y, sum, depth + 1);
    func(x, y + 1, sum, depth + 1);
    func(x, y - 1, sum, depth + 1);
    vst[x][y] = 0;
    ans.pop_back();
    op = tmp_op;
    sum = tmp_sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    m = m * 2 - 1; // m개의 숫자 -> m개의 칸

    for (int i = 0; i < 3; i++) {
        cin >> str;
        for (int j = 0; j < 3; j++) {
            board[i][j] = str[j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j || i + j == 2) {
                sum = 0;
                func(i, j, 0, 0);
            }
            if (ok) break;
        }
        if (ok) break;
    }

    if (!ok) cout << "0";

    return 0;
}