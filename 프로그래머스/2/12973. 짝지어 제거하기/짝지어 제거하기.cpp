#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    stack<char> stk;
    stk.push(s[0]);
    
    for (int i=1;i<s.size();i++) {
        if (stk.empty()) {
            stk.push(s[i]);
            continue;
        }
        
        char prev = stk.top();
        char cur = s[i];
        
        if (prev == cur) stk.pop();
        else stk.push(s[i]);
    }
    
    if (stk.empty()) return 1;
    return 0;
}