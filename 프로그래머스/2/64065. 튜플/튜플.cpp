#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

bool comp(pair<int,int>& a, pair<int,int>& b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    unordered_map<int, int> m;
    
    for(int i=0;i<s.length();i++) {
        char cur = s[i];
        
        if (cur >= '0' && cur <= '9') {
            string num = "";
            num += cur;
            
            int idx = i;
            
            while(1) {
                idx++;
                if (s[idx] < '0' || s[idx] > '9') break;
                num += s[idx];
            }
            
            i = idx - 1;
            m[stoi(num)]++;
        }
    }
    
    vector<pair<int,int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);
    
    vector<int> answer;
    
    for (int i=0;i<v.size();i++) {
        answer.push_back(v[i].first);
    }
    
    return answer;
}