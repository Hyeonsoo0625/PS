#include <iostream>
#include <cstring>
using namespace std;

int n;
int value;
int a;
int maxheap[100001];
int minheap[100001];
int size1 = 0;
int size2 = 0;
void maxheap_push(int data) {
	maxheap[++size1] = data;
	int i = size1;
	while ((i != 1) && data > maxheap[i / 2]) {
		maxheap[i] = maxheap[i / 2];
		i /= 2;
	}
	maxheap[i] = data;
}
int maxheap_pop() {
	int parent, child;
	int item, temp;
	item = maxheap[1];
	temp = maxheap[size1--];
	parent = 1;
	child = 2;
	while (child <= size1) {
		if ((child < size1) && maxheap[child] < maxheap[child + 1]) {
			child++;
		}
		if (temp >= maxheap[child]) {
			break;
		}
		maxheap[parent] = maxheap[child];
		parent = child;
		child *= 2;
	}
	maxheap[parent] = temp;
	return item;
}
void minheap_push(int data) {
	minheap[++size2] = data;
	int i = size2;
	while ((i != 1) && data < minheap[i / 2]) {
		minheap[i] = minheap[i / 2];
		i /= 2;
	}
	minheap[i] = data;
}
int minheap_pop() {
	int parent, child;
	int item, temp;
	item = minheap[1];
	temp = minheap[size2--];
	parent = 1;
	child = 2;
	while (child <= size2) {
		if ((child < size2) && minheap[child] > minheap[child + 1]) {
			child++;
		}
		if (temp <= minheap[child]) {
			break;
		}
		minheap[parent] = minheap[child];
		parent = child;
		child *= 2;
	}
	minheap[parent] = temp;
	return item;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int sum = 0;
	memset(maxheap, 0, 100001);
	memset(minheap, 0, 100001);
	size1 = 0;
	size2 = 0;
	cin >> n >> value;
	cout << value << '\n';
	maxheap_push(value);
	for (int i = 0; i < n - 1; i++) {
		cin >> a;
		if (a > maxheap[1]) {
			minheap_push(a);
		}
		else {
			maxheap_push(a);
		}
		if (size1 < size2) {
			maxheap_push(minheap_pop());
		}
		else if (size1 - 1 > size2) {
			minheap_push(maxheap_pop());
		}
		sum = maxheap[1];
		cout << sum << '\n';
	}
}