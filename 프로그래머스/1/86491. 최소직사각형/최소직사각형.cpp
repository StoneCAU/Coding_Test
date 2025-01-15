#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int x = 0;
    int y = 0;
    
    for (int i=0;i<sizes.size();i++) {
        vector<int> size = sizes[i];
        sort(size.begin(), size.end(), greater<int>());
        
        x = max(x, size[0]);
        y = max(y, size[1]);
    }
        
    answer = x * y;
    
    return answer;
}