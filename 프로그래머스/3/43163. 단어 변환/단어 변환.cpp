#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool isChangable(string cur, string next) {
    int num = 0;
    
    for (int i=0;i<cur.length();i++) {
        if (cur[i] == next[i]) num++;
    }
    
    if (num >= cur.length() - 1) return true;
    return false;
}

bool hasTargetChar(string next, string target) {
    for (int i=0;i<next.length();i++) {
        if (next[i] == target[i]) return true;
    }
    return false;
}

int getSameCount(string a, string b) {
    int count = 0;
     for (int i=0;i<a.length();i++) {
        if (a[i] == b[i]) count++;
    }
    return count;
}

int solution(string begin, string target, vector<string> words) {
    queue<pair<string, int>> q;
    vector<int> visited(51, 0);
    
    q.push({begin, -1});
    
    while (!q.empty()) {
        string cur = q.front().first;
        int curIndex = q.front().second;
        q.pop();
                
        if (cur == target) return visited[curIndex];
        
        for (int i=0;i<words.size();i++) {
            string next = words[i];
            
            if (!isChangable(cur, next)) continue;
            if (!hasTargetChar(next, target)) continue;
            if (visited[i]) continue;
            if (getSameCount(cur, target) == cur.length() - 1) {
                if (next == target) return visited[curIndex] + 1;
                else continue;
            }
            
            if (curIndex == -1) visited[i]++;
            else visited[i] = visited[curIndex] + 1;
            q.push({next, i});
        }
    }
    
    return 0;
}