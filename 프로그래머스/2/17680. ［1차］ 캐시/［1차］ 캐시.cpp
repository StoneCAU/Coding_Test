#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    deque<string> dq;
    
    for (int i=0;i<cities.size();i++) {
        string cur = cities[i];
        bool cache = false;
        int index = -1;
        
        for (int j=0;j<cur.size();j++) {
            if (cur[j] >= 'A' && cur[j] <= 'Z') {
                cur[j] = tolower(cur[j]);
            }
        }
        
        for (int j=0;j<dq.size();j++) {
            if (dq[j] == cur) {
                cache = true;
                index = j;
                break;
            }
        }
        
        if (cache) {
            answer++;
            string hit = dq[index];
            dq.erase(dq.begin() + index);
            dq.push_back(hit);
        }
        else {
            answer += 5;
            
            dq.push_back(cur);

            if (dq.size() > cacheSize) {
                dq.pop_front();
            }
        }
        
    }
    
    return answer;
}