#include <iostream>
#include <cmath>
using namespace std;

int N;
double arr[250010];
double cnt = 0;
int res = 0;
int flag = false;
int firstcnt = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] == 0) {
            if (!flag) {
                firstcnt++;
            }
            else if ((i + 1 == N) && arr[0] == 0) {
                res += ceil((cnt + firstcnt) / 2);
                firstcnt = 0;
            }
            else {
                cnt++;
            }
        }
        else {
            if (flag) {
                if ((i + 1 == N) && arr[0] == 0) {
                    res += ceil((cnt + firstcnt) / 2);
                    firstcnt = 0;
                }
                else {
                    res += arr[i] + ceil(cnt / 2);
                    cnt = 0;
                }
            }
            else {
                flag = true;
                res += arr[i];
            }
        }
    }
    if (firstcnt) {
        res += ceil(cnt + firstcnt / 2);
    }
    else if (cnt) {
        res += ceil(cnt/2);
    }
    cout << res;
}
