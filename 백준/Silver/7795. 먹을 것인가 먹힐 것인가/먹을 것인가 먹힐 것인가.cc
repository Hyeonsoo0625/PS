#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t;
int n, m;
int a;
vector<int> v1, v2;
int binarySearch(int target, vector<int> v) {
	int min = 0;
	int max = v.size() - 1;
	while (1) {
		int mid = (min + max) / 2 + 1;

		if (min == max) {
			return mid;
		}
		else if (v[mid] > target) {
			max = mid;
		}
		else if (v[mid] < target) {
			min = mid;
		}
		else {
			return mid;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	for (int i = 0; i < t; i++) {
		v1.clear();
		v2.clear();
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			cin >> a;
			v1.emplace_back(a);
		}
		for (int j = 0; j < m; j++) {
			cin >> a;
			v2.emplace_back(a);
		}
		int cnt = 0;
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (v1[j] > v2[k]) {
					cnt++;
				}
				else {
					break;
				}
			}
		}
		cout << cnt << '\n';
	}
}
