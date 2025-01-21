#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for (int i=0;i<s.length();i++) {
        stack<char> stk;
        
        for (int j=i;j<s.length() + i;j++) {
            char next = s[j % s.length()];
                        
            if (stk.empty()) {
                stk.push(next);
                continue;
            }
            
            char top = stk.top();
            
            if (top == '(' && next == ')') stk.pop();
            else if (top == '{' && next == '}') stk.pop();
            else if (top == '[' && next == ']') stk.pop();
        
            else stk.push(next);
        }
        
        
        if (stk.empty()) answer++;
    }
    
    
    
    return answer;
}