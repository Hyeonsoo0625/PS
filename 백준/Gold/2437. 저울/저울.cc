#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n, a;
	cin >> n;
	vector<int> pq;
	for (int i = 0; i < n; i++) {
		cin >> a;
		pq.emplace_back(a);
	}
	sort(pq.begin(), pq.end());
	int result = 1;
	for (int i = 0; i < pq.size(); i++) {
		if (result < pq[i]) {
			break;
		}
		else {
			result += pq[i];
		}
	}
	cout << result << '\n';
}