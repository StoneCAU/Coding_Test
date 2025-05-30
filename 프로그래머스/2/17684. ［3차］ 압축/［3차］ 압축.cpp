#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    unordered_map<string,int> map;
    int n = 1;
    
    // 초기화
    for (char c = 'A';c<='Z';c++) {;
       map[string(1, c)] = n++; 
    }
    
    int idx = 0;
    
    while(idx < msg.length()) {
        string w = string(1, msg[idx]);
        string t;
                
        while(1) {
            t = w; // temp
            w += msg[++idx];
            
            cout << t << " "<< w << "\n";
            
            if (!map[w]) {
                map[w] = n++;
                answer.push_back(map[t]);
                break;
            }
        }
    }
    
    return answer;
}