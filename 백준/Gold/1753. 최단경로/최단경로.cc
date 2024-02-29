#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e, start;
int a, b, c;
vector<pair<int, int>> d[20001];
int arr[20001];
priority_queue<pair<int, int>> pq;
void dijkstra() {
	pq.push({ 0, start });
	arr[start] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (arr[cur] < dist) {
			continue;
		}
		for (int i = 0; i < d[cur].size(); i++) {
			int nextD = dist + d[cur][i].second;
			if (arr[d[cur][i].first] > nextD) {
				arr[d[cur][i].first] = nextD;
				pq.push(make_pair(-nextD, d[cur][i].first));
			}
		}
	}
}
void solve() {
	for (int i = 1; i <= v; i++) {
		arr[i] = 1e9;
	}
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		d[a].emplace_back(make_pair(b, c));
	}
	dijkstra();
	for (int i = 1; i <= v; i++) {
		if (arr[i] == 1e9) {
			cout << "INF" << '\n';
		}
		else {
			cout << arr[i] << '\n';
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> v >> e;
	cin >> start;
	solve();
}