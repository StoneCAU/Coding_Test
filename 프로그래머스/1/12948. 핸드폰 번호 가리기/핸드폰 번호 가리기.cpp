#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int starLength = phone_number.length() - 4;
    
    for(int i=0;i<starLength;i++) {
        answer += "*";
    }
    
    for(int i=starLength;i<phone_number.length();i++) {
        answer += phone_number[i];
    }
    
    return answer;
}