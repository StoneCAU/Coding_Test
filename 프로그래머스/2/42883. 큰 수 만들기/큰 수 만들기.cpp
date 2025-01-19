#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int startIdx = 0;
    
    for(int i=0;i<number.length()-k;i++) {
        int maxNum = number[startIdx] - '0';
        int maxIdx = startIdx;
        
        for (int j=startIdx;j<=k+i;j++) {
            if (maxNum < number[j] - '0') {
                maxNum = number[j] - '0';
                maxIdx = j;
            }
        }
        startIdx = maxIdx + 1;
        answer += to_string(maxNum);
    }
    
    
    return answer;
}