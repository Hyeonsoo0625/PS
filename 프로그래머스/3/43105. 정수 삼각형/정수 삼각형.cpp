#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> tri = triangle;
    for(int i=0;i<triangle.size()-1;i++){
        for(int j=0;j<triangle[i].size();j++){
            tri[i+1][j] = max(tri[i+1][j], tri[i][j] + triangle[i+1][j]);
            tri[i+1][j+1] = max(tri[i+1][j + 1], tri[i][j] + triangle[i+1][j+1]);
        }
    }
    sort(tri[tri.size()-1].begin(), tri[tri.size()-1].end());
    answer = tri[tri.size()-1][tri.size()-1];
    return answer;
}