#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, arr[1001][1001];
bool visited[1001][1001];
int result[1001][1001];
int issame[1001][1001];
queue<pair<int, int>> q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int a = 1;
vector<int> same;

bool isinside(int y, int x) {
	if (0 <= x && x < m && 0 <= y && y < n) {
		return true;
	}
	return false;
}

void bfs(int i, int j) {
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (isinside(ny, nx) && !visited[ny][nx] && arr[ny][nx] != 1) {
				q.emplace(make_pair(ny, nx));
				visited[ny][nx] = true;
				cnt++;
			}
		}
	}
	result[i][j] = cnt;
	q.emplace(make_pair(i, j));
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		issame[y][x] = a;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (isinside(ny, nx) && visited[ny][nx]) {
				q.emplace(make_pair(ny, nx));
				visited[ny][nx] = false;
				issame[ny][nx] = a;
				result[ny][nx] = cnt;
			}
		}
	}
	a++;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && issame[i][j] == 0) {
				q.emplace(make_pair(i, j));
				visited[i][j] = true;
				bfs(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				same.clear();
				int cnt = 1;
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (isinside(ny, nx) && find(same.begin(), same.end(), issame[ny][nx]) == same.end()) {
						same.emplace_back(issame[ny][nx]);
						cnt += result[ny][nx];
					}
				}
				cout << cnt % 10;
			}
			else {
				cout << 0;
			}
		}
		cout << '\n';
	}
}