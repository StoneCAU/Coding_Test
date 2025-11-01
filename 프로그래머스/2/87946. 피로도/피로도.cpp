#include<bits/stdc++.h>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = INT_MIN;
    
    vector<int> v;
    for (int i=0;i<dungeons.size();++i) {
        v.push_back(i);
    }
    
    do {
        int cur = k;
        
        // v[0]: 0번째 입장 던전 번호
        for (int i=0;i<v.size();++i) {
            int idx = v[i]; // 입장할 던전
            int need = dungeons[idx][0];
            int use = dungeons[idx][1];
            
            // 최소 피로도만큼 없을 경우 or 마지막 입장 경우
            // update하고 다음 순서로 이동
            if (cur - need < 0) {
                answer = max(answer, i);
                break;
            }
            
            if (i == v.size() - 1) {
                return (int) v.size();
            }
            
            cur -= use;
        }
        
        
        
    } while (next_permutation(v.begin(), v.end()));
    
    return answer;
}