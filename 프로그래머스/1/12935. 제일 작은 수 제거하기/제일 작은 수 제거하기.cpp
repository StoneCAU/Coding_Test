#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    int minNum=arr[0];
    
    for(int i=0;i<arr.size();i++) {
        minNum = min(minNum, arr[i]);
    }
    
    arr.erase(remove(arr.begin(), arr.end(), minNum), arr.end());
    
    if (arr.size() == 0) arr.push_back(-1);
    
    return arr;
}