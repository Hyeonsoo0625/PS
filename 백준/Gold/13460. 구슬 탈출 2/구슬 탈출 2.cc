#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
char arr[12][12];
bool visit[12][12][12][12];
typedef struct node {
	int rx, ry, bx, by, cnt;
}node;
void move(int& x, int& y, int& distance, int& i) {
	while (arr[y + dy[i]][x + dx[i]] != '#' && arr[y][x] != 'O') {
		y += dy[i];
		x += dx[i];
		distance++;
	}
}
void bfs(int Rx, int Ry, int Bx, int By) {
	queue<node> q;
	q.push({ Rx,Ry,Bx,By,0 });
	visit[Rx][Ry][Bx][By] = true;
    while (!q.empty()) {
		int _rx = q.front().rx;
		int _ry = q.front().ry;
		int _bx = q.front().bx;
		int _by = q.front().by;
		int count = q.front().cnt;
		q.pop();
		if (count >= 10) {
			cout << -1;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nrx = _rx, nry = _ry, nbx = _bx, nby = _by, rc = 0, bc = 0, ncount = count + 1;
			move(nrx, nry, rc, i);
			move(nbx, nby, bc, i);
			if (arr[nby][nbx] == 'O') {
				continue;
			}
			if (arr[nry][nrx] == 'O') {
				cout << ncount << '\n';
				return;
			}
			if (nrx == nbx && nry == nby) {
				if (rc > bc) {
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}
			if (visit[nrx][nry][nbx][nby]) {
				continue;
			}
			visit[nrx][nry][nbx][nby] = true;
			q.push({ nrx, nry, nbx, nby, ncount });
		}
    }
	cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    cin >> n >> m;
    string s;
	int rx, ry, bx, by;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j];
            if (arr[i][j] == 'R') {
                rx = j;
                ry = i;
            }
            else if (arr[i][j] == 'B') {
                bx = j;
                by = i;
            }
        }
    }
	bfs(rx, ry, bx, by);
}
