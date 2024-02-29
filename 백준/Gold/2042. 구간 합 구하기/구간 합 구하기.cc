#include <iostream>
using namespace std;

int n, m, k;
long long arr[2000001];

void segtreeInit() {

	for (int i = n - 1; i != 0; i--) {
		arr[i] = arr[i << 1] + arr[i << 1 | 1];
	}
}
void change(long long i, long long x) {
	i = i - 1;
	arr[i += n] = x;
	while (i >>= 1) {
		arr[i] = arr[i << 1] + arr[i << 1 | 1];
	}
}

long long query(int l, int r) {
	long long result = 0;
	l -= 1;
	for (l += n, r += n; l != r; l >>= 1, r >>= 1) {
		if (l & 1) {
			result += arr[l++];
		}
		if (r & 1) {
			result += arr[--r];
		}
	}
	return result;
}
void solve() {
	segtreeInit();
	long long a, b, c;
	
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			change(b, c);
		}
		else {
			cout << query(b, c) << '\n';
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i + n];
	}
	solve();
}