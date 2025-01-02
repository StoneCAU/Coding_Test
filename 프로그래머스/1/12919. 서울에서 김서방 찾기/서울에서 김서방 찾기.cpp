#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {    
    int index;
    
    for (int i=0;i<seoul.size();i++) {
        if (seoul[i] == "Kim") {
            index = i;
            break;
        }
    }
    
    return "김서방은 " + to_string(index) + "에 있다";
}