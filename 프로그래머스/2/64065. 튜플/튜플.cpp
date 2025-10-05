#include<bits/stdc++.h>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> tot;
    
    // 맨 앞, 뒤 대괄호 제거
    s = s.substr(1, s.length()-1);
    s = s.substr(0, s.length()-1);
    
    while(1) {
        if (s[0] == ',') s = s.substr(1, s.length()-1);
        int eIdx = s.find("}");
        
        vector<int> temp;
        string num = "";
        for (int i=1;i<=eIdx;++i) {
            if (s[i] == ',' || s[i] == '}') {
                temp.push_back(stoi(num));
                num = "";
            }
            else {
                num += s[i];
            }
        }
        
        tot.push_back(temp);
        if (eIdx == s.length()-1) break;
        s = s.substr(eIdx+1, s.length()-eIdx);
    }
    
    sort(tot.begin(), tot.end(), cmp);
    set<int> set;
    for (int i=0;i<tot.size();++i) {
        for (int j=0;j<tot[i].size();++j) {
            if (set.find(tot[i][j]) == set.end()) {
                set.insert(tot[i][j]);
                answer.push_back(tot[i][j]);
                break;
            }
        }
    }
    
    return answer;
}