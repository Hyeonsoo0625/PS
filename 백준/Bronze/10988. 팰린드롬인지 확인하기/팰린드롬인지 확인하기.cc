#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	cin >> s;
	int i = 0;
	int j = s.size() - 1;
	while (i < j) {
		if (s[i] == s[j]) {
			i++; j--;
			continue;
		}
		else {
			cout << 0 << '\n';
			return 0;
		}
	}
	cout << 1 << '\n';
}