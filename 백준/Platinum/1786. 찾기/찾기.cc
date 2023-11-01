#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getPi(string b) {
	int j = 0;
	int m = b.size();
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && b[i] != b[j]) {
			j = pi[j - 1];
		}
		if (b[i] == b[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}
vector<int> kmp(string s, string p) {
	vector<int> ans;
	auto pi = getPi(p);
	int n = (int)s.size(), m = (int)p.size(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string a, b;
	getline(cin, a);
	getline(cin, b);
	vector<int> res = kmp(a, b);
	cout << res.size() << '\n';
	for (auto i : res) {
		cout << i + 1 << " ";
	}
}