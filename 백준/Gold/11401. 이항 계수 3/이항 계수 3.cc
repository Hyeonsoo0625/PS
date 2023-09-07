#include <bits/stdc++.h>
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

long long result2 = 1;
long long half;
long long def(int);

int main() {
	IOS;
	int N, K;
	cin >> N >> K;
	long long result1 = 1;
	int a = N - K;
	int b = K;
	while (b != 0) {
		result2 = result2 * b % 1000000007;
		b--;
	}
	for (int i = N; i >= N - K + 1; i--) {
		result1 = result1 * i % 1000000007;
	}
	int c = 1000000005;
	result2 = def(c);
	cout << (result1 * result2) % 1000000007 << endl;
}

long long def(int x)
{
	if (x == 0) return 1;

	if (x % 2 == 1) return result2 * def(x - 1) % 1000000007;
	else
	{
		half = def(x / 2);
		return half * half % 1000000007;
	}
}