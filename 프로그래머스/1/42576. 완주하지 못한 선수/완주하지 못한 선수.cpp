#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_map<string, int> m;
    
    for (int i = 0;i<participant.size();i++) {
        m[participant[i]]++;
    }
    
    for (int i=0;i<completion.size();i++) {
        m[completion[i]]++;
    }
    
    vector<pair<string, int>> v(m.begin(), m.end());
    
    for(int i=0;i<v.size();i++) {
        if (v[i].second % 2 == 1) return v[i].first;
    }

}