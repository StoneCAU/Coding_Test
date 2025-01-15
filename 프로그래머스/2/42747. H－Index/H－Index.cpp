#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());

    int h = 0;

        for(int i=0;i<citations.size();i++) {
            int temp = min(citations[i], i+1);
            h = max(temp, h);
        }

    answer = h;
    
    return answer;
}