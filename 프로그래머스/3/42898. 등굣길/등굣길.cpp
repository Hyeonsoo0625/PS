#include <string>
#include <vector>

using namespace std;


int solution(int m, int n, vector<vector<int>> puddles) {
    
    vector<vector<int>> v(n+1, vector<int>(m+1, 1));

    for(int i=0;i<=m;i++){
        v[0][i] = 0;
    }
    for(int i=0;i<=n;i++){
        v[i][0] = 0;
    }
    for(int i=0;i<puddles.size();i++){
        v[puddles[i][1]][puddles[i][0]] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(v[i][j] == 0){
                continue;
            }
            else if(i==1&&j==1){
                continue;
            }
            v[i][j] = (v[i-1][j]+v[i][j-1]) % 1000000007;
        }
    }
    int answer = v[n][m];
    
    return answer;
}