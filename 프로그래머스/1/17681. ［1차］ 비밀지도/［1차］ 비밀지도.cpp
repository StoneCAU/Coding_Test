#include <bits/stdc++.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i=0;i<n;++i) {
        int num = arr1[i] | arr2[i];
        
        string temp = "";
        for (int j = 0; j < n; j++) {
            if (num % 2 == 1) temp += "#";
            else temp += " ";
            num /= 2;
        }
        
        reverse(temp.begin(), temp.end());
        answer.push_back(temp);
    }
    
    return answer;
}