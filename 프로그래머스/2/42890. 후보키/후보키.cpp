#include<bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> relation) {
    int row = relation.size();
    int col = relation[0].size();
    vector<int> candidateKeys;
    
    for (int mask = 1;mask < (1 << col); ++mask) {
        unordered_set<string> s;
        
        for (auto& r : relation) {
            string key = "";
            for (int i=0;i<col;++i) {
                if (mask & (1 << i)) {
                    key += r[i] + "|";
                }
            }
            s.insert(key);
        }
        
        if (s.size() != row) continue;
        
        bool isMinimal = true;
        for (int prev : candidateKeys) {
            if ((mask & prev) == prev) {
                isMinimal = false;
                break;
            }
        }
        
        if (isMinimal) {
            candidateKeys.push_back(mask);
        }
    }
    
    return candidateKeys.size();
}