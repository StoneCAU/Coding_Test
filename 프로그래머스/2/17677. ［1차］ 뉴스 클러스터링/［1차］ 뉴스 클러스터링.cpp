#include <bits/stdc++.h>

using namespace std;

bool check(string str) {
    for (int i=0;i<str.length();i++) {
        if (str[i] < 'a' || str[i] > 'z') return false;
    }
    return true;
}

int solution(string str1, string str2) {
    int answer = 0;
    int interNum = 0;
    int unionNum = 0;
    
    map<string, pair<int,int>> m;
    
    for (int i=0;i<str1.length();i++) {
        if (str1[i] >= 'A' && str1[i] <= 'Z')
        str1[i] = tolower(str1[i]);
    }
    
    for (int i=0;i<str2.length();i++) {
        if (str2[i] >= 'A' && str2[i] <= 'Z')
        str2[i] = tolower(str2[i]);
    }
    
    for (int i=0;i<str1.length()-1;i++) {        
            string s = "";
        
        
            s += str1[i];
            s += str1[i+1];

            if (!check(s)) continue;
            if (s.length() == 1) continue;

            m[s].first++;
    } 
    
    for (int i=0;i<str2.length();i++) {        
            string s = "";
        
            if (i+1 == str2.length()) break;
        
            s += str2[i];
            s += str2[i+1];
        
            if (!check(s)) continue;
            if (s.length() == 1) continue;
            
            m[s].second++;
    } 
    
    
    for(auto it:m) {
        interNum += min(it.second.first, it.second.second);
        unionNum += max(it.second.first, it.second.second);
    }
    
    if (interNum == 0 && unionNum == 0) answer = 65536;
    else answer = (float)interNum / unionNum * 65536;
    
    return answer;
}