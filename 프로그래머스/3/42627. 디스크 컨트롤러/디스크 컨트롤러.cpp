#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

struct cmp {
    bool operator()(vector<int> &a, vector<int> &b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int curTime = 0;
    int i = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    sort(jobs.begin(), jobs.end());
    
    while(1) {
        if (pq.empty() && i >= jobs.size()) break;
        
        if (i < jobs.size() && curTime >= jobs[i][0]) {
            pq.push(jobs[i]);
            i++;
            continue;
        }
        
        if (!pq.empty()) {
            curTime += pq.top()[1];
            answer += curTime - pq.top()[0];
            pq.pop();
        } 
        else {
            curTime = jobs[i][0];
        }
        
    }
    
    return answer / jobs.size();
}