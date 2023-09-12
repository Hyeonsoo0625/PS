#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[9];
bool visited[9];
int num[10];

void dfs(int cnt)
{
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            arr[cnt] = num[i];
            visited[i] = true;
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    dfs(0);
}