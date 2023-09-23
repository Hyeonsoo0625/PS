#include <iostream>
#include <vector>
using namespace std;

vector<int> p(500001, 0);

int find(int node) {
	if (p[node] == node) {
		return node;
	}
	return p[node] = find(p[node]);
}

void merge(int node1, int node2) {
	p[node1] = node2;
}
int flag = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		p[i] = i;
	}
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		int c = find(a);
		int d = find(b);
		if (c == d) {
			flag = i + 1;
			break;
		}
		else {
			merge(c, d);
		}
	}
	cout << flag;
}