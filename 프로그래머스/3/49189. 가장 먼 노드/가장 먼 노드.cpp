#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> q;
vector<int> v[20001];
vector<pair<int, int>> res;
int curCount[20001]; //수정 필요
bool arr[20001] = {false};
int cur = 1;
void bfs(){
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0; i<v[now].size(); i++){
            if(arr[v[now][i]] != true){
                q.emplace(v[now][i]);
                res.emplace_back(make_pair(curCount[now]+1, v[now][i]));
                curCount[v[now][i]] = curCount[now] + 1;
                arr[v[now][i]] = true;
            }
        }
        
    }
}
int solution(int n, vector<vector<int>> edge) {
        int answer = 0;
    for(int i=0;i<edge.size();i++){
        v[edge[i][0]].emplace_back(edge[i][1]);
        v[edge[i][1]].emplace_back(edge[i][0]);
    }
    q.emplace(1);
    curCount[1] = 1;
    res.emplace_back(make_pair(cur, 1));
    arr[1] = true;
    bfs();
    sort(res.begin(), res.end());
    int max1 = res[res.size()-1].first;
    int j = res.size()-1;
    while(res[j].first == max1){
        answer++;
        j--;
    }
    return answer;
}