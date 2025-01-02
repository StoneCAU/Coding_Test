#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> split(string input, char delimiter) {
    vector<int> res;
    stringstream ss(input);
    string temp;
    
    while (getline(ss, temp, delimiter)) {
        res.push_back(stoi(temp));
    }
    
    return res;
}

string solution(string s) {
    string answer = "";
    vector<int> numbers = split(s, ' ');
    
    int minNum = numbers[0];
    int maxNum = numbers[0];
    
    for (int i=0;i<numbers.size();i++) {
        int num = numbers[i];
        minNum = min(minNum, num);
        maxNum = max(maxNum, num);
    }
    
    answer += to_string(minNum);
    answer += " ";
    answer += to_string(maxNum);
    
    return answer;
}