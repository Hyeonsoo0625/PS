#include <iostream>
#include <vector>
using namespace std;

int N, Q, a, L, R;
vector<long long> v, sum;
#include <algorithm>
int binary_search(int target, vector<int> v, int a) {
	int left = 0;
	int right = v.size() - 1;
	int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (v[mid] > target) {
			right = mid - 1;
		}
		else if (v[mid] < target) {
			left = mid + 1;
		}
		else if (v[mid]==target) {
			return mid;
		}
	}
	if (a == 0) {
		return left;
	}
	else {
		return right;
	}
}
long long getDis(int low, int high, int j) {
	long long left = (long long)(j - low + 1) * v[j] - (sum[j] - sum[low - 1]);
	long long right = (sum[high] - sum[j - 1]) - (long long)(high - j + 1) * v[j];

	return left + right;
}
int main() {
	cin >> N >> Q;
	sum.emplace_back(0);
	v.emplace_back(0);
	for (int i = 1; i <= N; i++) {
		cin >> a;
		v.emplace_back(a);
		sum.emplace_back(sum[i - 1] + a);
	}
	for (int i = 0; i < Q; i++) {
		cin >> L >> R;
//		int lidx = binary_search(L, v, 0);
//		int ridx = binary_search(R, v, 1);
		int lidx = lower_bound(v.begin(), v.end(), L) - v.begin();
		int ridx = upper_bound(v.begin(), v.end(), R) - v.begin() - 1;
		if (lidx >= ridx) {
			cout << 0 << '\n';
			continue;
		}
		long long max1 = max(getDis(lidx, ridx, lidx), getDis(lidx, ridx, ridx));
		long long min1 = getDis(lidx, ridx, (lidx + ridx) / 2);
		cout << max1 - min1 << '\n';
	}
}