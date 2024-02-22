#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


unordered_map<string, int> m;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size(); i++) {
        string s = "";
        for (int j = 0; j < phone_book[i].size(); j++) {
            s += phone_book[i][j];
            if (m.find(s)!=m.end()) {
                answer = false;
                return answer;
            }
        }
        m.insert(make_pair(phone_book[i], i));
    }
    return answer;
}