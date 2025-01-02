#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk;
    stk.push(s[0]);

    for (int i=1;i<s.size();i++) {
        if (stk.empty()) {
            stk.push(s[i]);
            continue;
        }
        
        char prev = stk.top();
        stk.push(s[i]);
        
        if(prev == '(' && stk.top() == ')') {
            stk.pop();
            stk.pop();
        }
    }

    return stk.empty();
}