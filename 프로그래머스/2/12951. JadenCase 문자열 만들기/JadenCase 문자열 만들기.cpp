#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isFirst = true;
    
    for(auto c : s) {
        if (c == ' ') {
            isFirst = true;
            answer += " ";
        }
        else if (isFirst) {
            isFirst = false;
            answer += toupper(c);
        }
        else {
            answer += tolower(c);
        }
    }
    
    return answer;
}