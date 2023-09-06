#include <iostream>
using namespace std;

int a, b, c;

long long fun(long long y) {
	if (y == 1) {
		return a % c;
	}
	long long k = fun(y / 2) % c;
	if (y % 2 == 0) {
		return k * k % c;
	}
	else {
		return k * k % c * a % c;
	}
}
int main() {
	cin >> a >> b >> c;
	cout << fun(b);
}