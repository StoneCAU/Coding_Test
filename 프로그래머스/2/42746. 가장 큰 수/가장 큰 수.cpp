#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b) {    
    string c = to_string(a);
    string d = to_string(b);
    
    return c+d > d+c;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), cmp);
    
    for (int i=0;i<numbers.size();i++) {
        answer += to_string(numbers[i]);
    }
    
    if (answer[0] == '0') {
        while(1) {
            if (answer[0] != '0') break;
            answer.erase(answer.begin());
        }
        answer += "0";
    }
    
    return answer;
}