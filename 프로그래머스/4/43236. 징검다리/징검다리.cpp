#include<bits/stdc++.h>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    
    // 2 11 14 17 21
    // low = 0, high = 25, mid = 12
    int low = 0;
    int high = distance;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int remove = 0;
        int cur = 0;
        
        for (auto rock : rocks) {
            if (rock - cur < mid) remove++;
            else cur = rock;
        }
        
        if (distance - cur < mid) remove++;
        
        if (remove > n) {
            high = mid - 1;
        }
        else {
            answer = mid;
            low = mid + 1;
        }
    }
    
    return answer;
}