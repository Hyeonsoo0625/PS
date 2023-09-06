#include <iostream>
#include <vector>
using namespace std;

struct Node {
	char left;
	char right;
};
vector<Node> v(90);

int n;
char no, l, r;

//preorder
void preorder(char start) {
	if (start == '.') {
		return;
	}
	cout << start;
	preorder(v[start].left);
	preorder(v[start].right);
}

//inorder
void inorder(char start) {
	if (start == '.') {
		return;
	}
	inorder(v[start].left);
	cout << start;
	inorder(v[start].right);
}

//postorder
void postorder(char start) {
	if (start == '.') {
		return;
	}
	postorder(v[start].left);
	postorder(v[start].right);
	cout << start;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> no >> l >> r;
		v[no].left = l;
		v[no].right = r;
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
}