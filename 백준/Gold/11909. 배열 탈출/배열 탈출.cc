#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int v[2223][2223];
int res[2223][2223];
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

bool isInside(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

void bfs() {
	res[0][0] = 0;
	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int money = pq.top().first;
		pq.pop();
		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int next = money;
			if (isInside(nx, ny)) {
				if (v[ny][nx] >= v[y][x]) {
					next += (v[ny][nx] - v[y][x] + 1);
				}
				if (next >= res[ny][nx]) {
					continue;
				}
				res[ny][nx] = next;
				pq.emplace(make_pair(next, make_pair(nx, ny)));

			}
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res[i][j] = 1e9;
			cin >> v[i][j];
		}
	}
	pq.emplace(make_pair(0, make_pair(0, 0)));
	bfs();
	cout << res[n - 1][n - 1];

}