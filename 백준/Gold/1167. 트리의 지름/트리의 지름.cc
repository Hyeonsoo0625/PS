#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int V;
int s, e, w;
vector<pair<int, int>> v[100001];
bool visit[100001];
int max1 = 0;
int maxnode;

void dfs(int start, int dist) {
	if (visit[start]) {
		return;
	}
	if (max1 < dist) {
		max1 = dist;
		maxnode = start;
	}
	visit[start] = true;
	for (int i = 0; i < v[start].size(); i++) {
		int nexti = v[start][i].first;
		int nextd = v[start][i].second;
		dfs(nexti, nextd + dist);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> V;
	for (int i = 0; i < V; i++) {
		cin >> s;
		cin >> e;
		while (e != -1) {
			cin >> w;
			v[s].emplace_back(make_pair(e, w));
			v[e].emplace_back(make_pair(s, w));
			cin >> e;
		}
	}
	dfs(1, 0);
	memset(visit, 0, sizeof(visit));
	max1 = 0;
	dfs(maxnode, 0);
	cout << max1 << '\n';
}