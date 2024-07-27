#include <iostream>
using namespace std;

int N, Q, a, L, R;
long long  v[200010], sum[200010];

int binary_search(int target, long long v[], int a, int vsize) {
	int left = 0;
	int right = vsize - 1;
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
	return (long long)(2 * j - low - high) * v[j] - (sum[j] - sum[low - 1]) + (sum[high] - sum[j - 1]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		v[i] = a;
		sum[i] = sum[i - 1] + a;
	}
	for (int i = 0; i < Q; i++) {
		cin >> L >> R;
		int lidx = binary_search(L, v, 0, N+1);
		int ridx = binary_search(R, v, 1, N+1);
		if (lidx >= ridx) {
			cout << 0 << '\n';
			continue;
		}
		long long max1 = max(getDis(lidx, ridx, lidx), getDis(lidx, ridx, ridx));
		long long min1 = getDis(lidx, ridx, (lidx + ridx) / 2);
		cout << max1 - min1 << '\n';
	}
}