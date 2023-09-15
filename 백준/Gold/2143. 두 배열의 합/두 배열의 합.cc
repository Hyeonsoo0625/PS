#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, num, a, sum;
vector<int> v1, v2, accumV1, accumV2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long cnt = 0;
	cin >> t >> num;
	for (int i = 0; i < num; i++) {
		cin >> a;
		v1.emplace_back(a);
	}
	//v1 누적합
	for (int i = 0; i < num; i++) {
		sum = 0;
		for (int j = i; j < num; j++) {
			sum += v1[j];
			accumV1.emplace_back(sum);
		}
	}
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a;
		v2.emplace_back(a);
	}
	//v2 누적합
	for (int i = 0; i < num; i++) {
		sum = 0;
		for (int j = i; j < num; j++) {
			sum += v2[j];
			accumV2.emplace_back(sum);
		}
	}
	sort(accumV1.begin(), accumV1.end());
	for (int i = 0; i < accumV2.size(); i++) {
		auto up = upper_bound(accumV1.begin(), accumV1.end(), t - accumV2[i]);
		auto lo = lower_bound(accumV1.begin(), accumV1.end(), t - accumV2[i]);
		cnt += up - lo;
	}
	cout << cnt;
}