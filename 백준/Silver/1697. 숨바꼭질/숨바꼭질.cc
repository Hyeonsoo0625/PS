#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<pair<int, int>> q;
bool isVisited[200001] = { false };

bool findValid(int a) {
	if (a < 0 || a>100001 || isVisited[a]) {
		return false;
	}
	return true;
}
int dfs() {

	while (1) {
		int a = q.front().first;
		int b = q.front().second;
		if (a == K) {
			return b;
		}

		if (findValid(a - 1)) {
			isVisited[a - 1] = true;
			q.emplace(a - 1, b + 1);
		}
		if (findValid(a + 1)) {
			isVisited[a + 1] = true;
			q.emplace(a + 1, b + 1);
		}
		if (findValid(a * 2)) {
			isVisited[a * 2] = true;
			q.emplace(a * 2, b + 1);
		}
		q.pop();

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> K;
	isVisited[N] = true;
	q.emplace(N, 0);
	cout << dfs();
}
