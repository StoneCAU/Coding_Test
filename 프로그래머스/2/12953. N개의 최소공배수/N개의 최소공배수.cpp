#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    int maxNum = arr[0];
    
    for(int i=1;i<arr.size();i++) {
        maxNum = max(maxNum, arr[i]);
    }
    
    for(int i=maxNum;i<=100000000;i++) {
        bool chk = false;
        
        for(int j=0;j<arr.size();j++) {
            if (i % arr[j] != 0) break;
            if (j == arr.size() - 1) chk = true;
        }
        
        if (chk) return i;
    }
    
    return answer;
}