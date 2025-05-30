#include<bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    for (int i=1;i<=s.length() / 2;i++) {
        string prev = s.substr(0, i);
        int cnt = 1;
        string com = "";
        
        for (int j = i;j<s.length();j+=i) {
            string cur = s.substr(j, i);
            
            if (prev == cur) {
                cnt++;
            }
            else {
                if (cnt >= 2) {
                    com += to_string(cnt);
                }
                com += prev;
                
                cnt = 1;
                prev = cur;
            }
        }
        
         if (cnt >= 2) {
            com += to_string(cnt);
        }
        com += prev;

        
        answer = min(answer, (int)com.length());
    }
    
    
    return answer;
}