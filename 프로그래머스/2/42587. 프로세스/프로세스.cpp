#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int,int>> q; // (0,2), (1,1), (2,3), (3,2)
    priority_queue<int> pq; // 9 1 1 1 1 1 
    
    for(int i=0;i<priorities.size();i++) {
        pq.push(priorities[i]);
        q.push({i, priorities[i]});
    }
    
    while (!q.empty()) {        
        pair<int,int> qfront = q.front();
        int max_element = pq.top();
        
        q.pop();
        
        if(qfront.second < max_element) {
            q.push(qfront);
        }
        else {
            pq.pop();
            answer++;
            if(location == qfront.first) break;
        }
        
    }
    
    
    return answer;
}