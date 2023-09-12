#include <iostream>
using namespace std;

int a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> b;
	int res = 1;
	while (b != a) {
		res += 1;
		int tmp = b;
		if (b % 10 == 1) {
			b /= 10; //1빼기
		}
		else if (b % 2 == 0) {
			b /= 2; //2나누기
		}
		if (tmp == b) {
			cout << -1 << '\n';
			return 0;
		}
	
	}
	cout << res << '\n';
}