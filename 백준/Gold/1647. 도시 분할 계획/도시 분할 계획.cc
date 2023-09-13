#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a, b, c;
vector<pair<int, pair<int, int>>> v;
int parent[100001];
int res = 0;

int find(int node) {
	if (parent[node] == node) {
		return node;
	}
	else {
		return find(parent[node]);
	}
}
void union1(int x, int y) {
	x = find(x);
	y = find(y);
	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v.emplace_back(make_pair(c, make_pair(a, b)));
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	vector<int> save;
	sort(v.begin(), v.end());
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		a = v[i].second.first;
		b = v[i].second.second;
		c = v[i].first;
		if (find(a) != find(b)) {
			union1(a, b);
			save.emplace_back(c);
		}
	}
	for (int i = 0; i < save.size() - 1; i++) {
		res += save[i];
	}
	cout << res << '\n';
}