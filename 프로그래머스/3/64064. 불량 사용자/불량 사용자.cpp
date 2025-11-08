#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> matches; // matches[벤id] = 유저id
set<int> cases;

bool isMatch(string user, string banned) {
    if (user.size() != banned.size()) return false;
    for (int i=0;i<user.size();++i) {
        if (banned[i] == '*') continue;
        if (user[i] != banned[i]) return false;
    }
    return true;
}

void dfs(int idx, int mask) {
    if (idx == matches.size()) {
        cases.insert(mask);
        return;
    }
    
    for (int uid : matches[idx]) {
        if (mask & (1 << uid)) continue;
        dfs(idx+1, mask | (1 << uid));
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    matches.resize(banned_id.size());
    
    for (int i=0;i<banned_id.size();++i) {
        for (int j=0;j<user_id.size();++j) {
            if (isMatch(user_id[j], banned_id[i])) {
                matches[i].push_back(j);
            }
        }
    }
    
    dfs(0,0);
    
    return cases.size();
}