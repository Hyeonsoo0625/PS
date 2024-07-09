#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m;

int parent[1000001];
set<int> s;

int index(int i, int j, int m) {
	return i * m + j;
}
int findParent(int node) {
	if (node == parent[node])
		return node;
	return parent[node] = findParent(parent[node]);
}

void union1(int n1, int n2) {
	n1 = findParent(n1);
	n2 = findParent(n2);
	if (n1 > n2) {
		parent[n1] = n2;
	}
	else if (n1 < n2) {
		parent[n2] = n1;
	}
	else {
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'S') {
				union1(index(i, j, m), index(i + 1, j, m));
			}
			else if (s[j] == 'N') {
				union1(index(i, j, m), index(i - 1, j, m));
			}
			else if (s[j] == 'E') {
				union1(index(i, j, m), index(i, j + 1, m));
			}
			else {
				union1(index(i, j, m), index(i, j - 1, m));
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		s.insert(findParent(parent[i]));
	}
	cout << s.size();
}