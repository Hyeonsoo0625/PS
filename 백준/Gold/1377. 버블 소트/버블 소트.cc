#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;


	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.emplace_back(make_pair(a, i));
	}
	sort(v.begin(), v.end());
	int min = -1;

	for (int i = 0; i < n; i++) {
		if (min < v[i].second - i) {
			min = v[i].second - i;
		}
	}
	cout << min + 1;

}
