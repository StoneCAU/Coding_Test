#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    
    vector<int> participants;
    unordered_map<int, int> have;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    // 전부 다 1개씩 있다고 가정
    for (int i=1;i<=n;i++) {
        have[i] = 1;
    }
    
    // 여분이 있다면 + 1
    for (int i=0;i<reserve.size();i++) {
        have[reserve[i]]++;
    }
    
    // 도난당했다면 - 1
    for (int i =0;i<lost.size();i++) {
        have[lost[i]]--;
    }
    
    for (int i=0;i<lost.size();i++) {
        int need = lost[i];
        
        if (have[need]) continue;
        
        // 앞 사람 검사
        if (need > 1 && have[need - 1] > 1) {
            have[need - 1]--;
            have[need]++;
            continue;
        }
        
        // 뒷 사람 검사
        if (need < n && have[need + 1] > 1) {
            have[need + 1]--;
            have[need]++;
        }
    }
    
    for (int i=1;i<=n;i++) {
        if (!have[i]) answer--;
    }
    
    return answer;
}