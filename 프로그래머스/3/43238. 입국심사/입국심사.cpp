#include<bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long m = *max_element(times.begin(), times.end());
    long long low = 1;
    long long high = m * n;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long fin = 0;
                
        for (auto time : times) {
            fin += mid / time;
            
            if (fin >= n) break;
        }
        
        if (fin >= n) {
            high = mid - 1;
            answer = mid;
        }
        else low = mid + 1;
    }
    
    return answer;
}