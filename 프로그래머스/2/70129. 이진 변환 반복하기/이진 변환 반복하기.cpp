#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int getZeroNum(int len) {
    int count = 0;
    while (len != 1) {
        if (len % 2 == 0) count++;
        len /= 2;
    }
    
    return count;
}

int getLength(int len) {
    int count = 1;
    
    while (len != 1) {
        len /= 2;
        count++;
    }
    
    return count;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> temp;
    int tryCount = 1;
    int zero;
    int len = 0;
    
    for (int i=0; i<s.length(); i++) {
        if (s[i] == '1') len++;
    }
    
    zero = s.length() - len;
    
    while (len != 1) {
        int temp = getZeroNum(len);
        len = getLength(len);
        
        // 0 제거
        len -= temp;
        zero += temp;
        tryCount++;
    }
    
    answer.push_back(tryCount);
    answer.push_back(zero);

    
    return answer;
}