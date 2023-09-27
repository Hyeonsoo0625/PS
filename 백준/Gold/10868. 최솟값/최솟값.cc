#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a, b;
int arr[100001];
int segtree[200001];

void init() {
	for (int i = 0; i < n; i++) {
		segtree[i + n] = arr[i];
	}
	for (int i = n - 1; i != 0; --i) {
		segtree[i] = min(segtree[i<<1], segtree[i<<1 | 1]);
	}
}
int query(int l, int r) {
	int result = 1000000001;
	for (l += n, r += n; l != r; l >>= 1, r >>= 1) {
		if (l & 1) {
			result = min(result, segtree[l++]);
		}
		if (r & 1) {
			result = min(result, segtree[--r]);
		}
	}
	return result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init();
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << query(a-1, b) << '\n';
	}

}