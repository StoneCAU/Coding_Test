#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int index = 0;
    int sum = 0;
    
    while(sum != progresses.size()) {
        int cur = progresses[index];
        int need = 100 - progresses[index];
        int needCount = need / speeds[index];
        if (need % speeds[index] != 0) needCount++;
        
        for(int i=0;i<progresses.size();i++) {
            progresses[i] += needCount * speeds[i];
        }
        
        int count = 0;
        
        for (int j=index;j<progresses.size();j++) {
            if (progresses[j] >= 100) {
                count++;
            }
            else {
                index = j;
                break;
            }
        }  
        
        if (count > 0) {
            answer.push_back(count);
            sum += count;
        }
        
    }
    
    return answer;
}