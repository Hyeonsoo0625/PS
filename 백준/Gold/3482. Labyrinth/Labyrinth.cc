#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tc, a, b;
string s;
int arr[1001][1001];
queue<pair<int, int>> q1;
pair<int, int> pa;
pair<int, int> start;
int isVisited[1001][1001] = { false };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool isInside(int y, int x) {
	return (y >= 0 && y < b && x >= 0 && x < a);
}

pair<int, int> bfs() {
	while (!q1.empty()) {
		int y = q1.front().first;
		int x = q1.front().second;
		q1.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!isVisited[ny][nx] && isInside(ny, nx) && arr[ny][nx] == '.') {
				isVisited[ny][nx] = true;
				q1.push({ ny, nx });
			}
		}
		if (q1.empty()) {
			pair<int, int> p = { y, x };
			return p;
		}
	}
}

int bfs1() {
	while (!q1.empty()) {
		int y = q1.front().first;
		int x = q1.front().second;
		q1.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!isVisited[ny][nx] && isInside(ny, nx) && arr[ny][nx] == '.') {
				isVisited[ny][nx] = true;
				arr[ny][nx] = arr[y][x] + 1;
				q1.push({ ny, nx });
			}
		}
		if (q1.empty()) {
			return arr[y][x];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> a >> b;
		for (int j = 0; j < b; j++) {
			cin >> s;
			for (int k = 0; k < a; k++) {
				arr[j][k] = s[k];
				if (s[k] == '.') {
					start.first = j;
					start.second = k;
				}
			}
		}
		isVisited[start.first][start.second] = true;
		q1.push(start);
		pa = bfs();
		for (int j = 0; j < a; j++) {
			for (int k = 0; k < b; k++) {
				isVisited[k][j] = false;
			}
		}
		arr[pa.first][pa.second] = 0;
		q1.push({ pa.first, pa.second });
		isVisited[pa.first][pa.second] = true;
		cout << "Maximum rope length is " << bfs1() << '.' << '\n';
		for (int j = 0; j < a; j++) {
			for (int k = 0; k < b; k++) {
				isVisited[k][j] = false;
			}
		}
	}
}