#define INF 1e9
#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b, c;
int arr[101][101];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (arr[a-1][b-1] > c) {
			arr[a-1][b-1] = c;
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == INF) {
				cout << 0 << " ";
			}
			else {
				cout << arr[i][j] << " ";
			}
		}
		cout << '\n';
	}
}
