#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
//#include <algorithm>
using namespace std;

vector <int> v[300001];
int N, M;
int a, b;
queue<int> q;
int arr[300001];
int result[300001];
int cnt = 1;

void BFS();

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	q.emplace(1);
	for (int i = 2; i <= N; i++) {
		result[i] = -1;
	}
	//result[1] = 1;
	BFS();
	//result[1] = 0;
	cout << 0 << '\n';
	for (int i = 2; i <= N; i++) {
		cout << result[i] << '\n';
	}
}

void BFS() {
	while (!q.empty()) {
		memset(arr, 0, sizeof(arr));
		int temp = q.size();
		while (!q.empty()) {
			for (int j = 0; j < v[q.front()].size(); j++) {
				arr[v[q.front()][j]]++;
			}
			q.pop();
		}
		for (int i = 1; i <= N; i++) {
			if (arr[i] < temp && result[i] == -1) {
				result[i] = cnt;
				q.emplace(i);
			}
		}
		//q.pop();
		cnt++;
	}
}
/*
6 5
1 6
2 6
3 6
4 6
1 5
0
1
1
1
2
3
*/